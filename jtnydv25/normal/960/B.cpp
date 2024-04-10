#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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
const int N = 1005;
int a[N], b[N];
ll dp[N][N];
const ll INF = 1e17;
int main(){
	int n, k1, k2;
	sd(n); sd(k1); sd(k2);
	for(int i = 1; i <= n; i++) sd(a[i]);
	for(int i = 1; i <= n; i++) sd(b[i]);
	int k = k1 + k2;
	multiset<int> st;
	long long curr = 0;
	for(int i = 1; i <= n; i++) st.insert(-abs(a[i] - b[i])), curr += (a[i] - b[i]) * 1ll * (a[i] - b[i]);
	for(int i = 1; i <= k; i++){
		auto it = *st.begin();
		if(it == 0){
			st.erase(st.find(0));
			st.insert(-1);
		}
		else{
			st.erase(st.find(it));
			st.insert(it + 1);
		}
	}
	long long ans= 0;
	for(auto it : st) ans += it * 1ll * it;
	printf("%lld\n", ans);
}