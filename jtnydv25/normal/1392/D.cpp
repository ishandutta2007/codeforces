#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 200005;
char s[N];
int mn(int n){
	return n <= 1 ? 0 : (n - 2) / 3 + 1;
}
int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);
		vector<bool> inCycle(n);
		vector<int> nxt(n);
		vector<int> indeg(n);
		bool bad = true;
		scanf("%s", s);
		for(int i = 0; i < n; i++){
			if(i && s[i] != s[0]) bad = false;
			if(s[i] == 'L'){
				nxt[i] = (i - 1 + n) % n;
			} else{
				nxt[i] = (i + 1) % n;
			}
			indeg[nxt[i]]++;
		}
		if(bad){
			printf("%d\n", 1 + mn(n - 2));
			continue;
		}

		for(int i = 0; i < n; i++) if(nxt[nxt[i]] == i) inCycle[i] = true;
		int ans = 0;
		for(int i = 0; i < n; i++) if(indeg[i] == 0){
			int curr = i, l = 0;
			while(!inCycle[curr]){
				curr = nxt[curr];
				l++;
			}
			ans += mn(l);
		}
		printf("%d\n", ans);
	}
}