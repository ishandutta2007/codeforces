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
const int N = 2005;
char s[N];
vector<pii> ans;
void rev(int l, int r){
	int mid = (l + r) / 2;
	for(int i = l; i <= mid; i++){
		if(i != l + r - i) swap(s[i], s[l + r - i]);
	}
}
void makeCharacter(int pos, char c, int n){
	if(s[pos] == c) return;
	for(int i = pos + 1; i < n; i++) if(s[i] == c){
		ans.push_back({pos + 1, i + 1});
		rev(pos, i);
		return;
	}
}

int main(){
	int t; sd(t);
	while(t--){
		ans.clear();
		int n, k; sd(n); sd(k);
		scanf("%s", s);
		for(int i = 0; i < k - 1; i++){
			makeCharacter(2 * i, '(', n);
			makeCharacter(2 * i + 1, ')', n);
		}
		int num = n / 2 - (k - 1);
		int pos = 2 * (k - 1);
		for(int i = 0; i < num; i++){
			makeCharacter(pos, '(', n);
			pos++;
		}
		for(int i = 0; i < num; i++){
			makeCharacter(pos, ')', n);
			pos++;
		}
		printf("%d\n", sz(ans));
		for(auto it : ans) printf("%d %d\n", it.F, it.S);
	}
}