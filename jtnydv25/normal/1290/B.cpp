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
int pref[26][N];
char s[N];
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int t; sd(t);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++) pref[j][i] = pref[j][i - 1];
		pref[s[i] - 'a'][i]++;
	}
	while(t--){
		int l, r;
		sd(l); sd(r);
		int len = r - l + 1;
		int cnt = 0;
		for(int j = 0; j < 26; j++){
			int num = pref[j][r] - pref[j][l - 1];
			if(num > 0) cnt++;
		}
		printf( (s[l] != s[r] || cnt > 2 || len == 1 || (cnt == 2 && len == 2)) ? "Yes\n" : "No\n");
	}
}