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
int a[5005];
int main(){
	int t, n, m, k;
	sd(t);
	while(t--){
		sd(n); sd(m); sd(k);
		for(int i = 1; i <= n; i++) sd(a[i]);
		k = min(k, m - 1);
		int rem = m - 1 - k;
		int ans = 0;
		for(int l = 0; l <= k; l++){
			int L = l + 1, R = n - (k - l);
			int val = INT_MAX;
			for(int j = 0; j <= rem; j++){
				// L + j, R - (rem - j)
				// trace(n, m, k, L, R, j);
				val = min(val, max(a[L + j], a[R - rem + j]));
			}
			ans = max(ans, val);
		}
		printf("%d\n", ans);
	}
}