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

const int N = 55;
ll pref[N];
ll mask = 0;
int n, k;
bool dp[N][N];
void add(int i){
	ll mask2 = mask | (1LL << i);
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = i; j >= 1; j--){
			ll sm = pref[i] - pref[j - 1];
			for(int l = 1; l <= k; l++){
				if(dp[j - 1][l - 1] && ((mask2 & sm) == mask2))
					dp[i][l] = 1;
			}
		}
	}
	if(dp[n][k]) mask = mask2;
}

int main(){
	sd(n); sd(k);
	for(int i = 1; i <= n;i++){
		ll x;
		scanf("%lld", &x);
		pref[i] = pref[i - 1] + x;
	}
	for(int i = 60; i >= 0; i--) add(i);
		printf("%lld\n", mask);
}