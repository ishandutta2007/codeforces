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
const int N = 1006;
char s[N];
char p[N];
int main(){
	int t; sd(t);
	while(t--){
		scanf("%s", s);
		int n = strlen(s);
		int ans = 1 << 30;
		for(int i = 0; i <= n; i++){
			int cnt = 0;
			for(int j = 0; j < i; j++) cnt += s[j] != '0';
			for(int j = i; j < n; j++) cnt += s[j] != '1';
			ans = min(ans, cnt);
			cnt = 0;
			for(int j = 0; j < i; j++) cnt += s[j] != '1';
			for(int j = i; j < n; j++) cnt += s[j] != '0';
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
}