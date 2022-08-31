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
const int mod= 998244353;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 3005;
int dp[N], old_dp[N];
int f[N][N];

int freq[N], freq2[N];
int a[N];
int pw2[N], invpw[N];
int val[1 << 10], val2[1 << 10];
int sgn[1 << 10];
inline int fix(int x){
	if(x < 0) x += mod;
	if(x >= mod) x -= mod;
	return x;
}
int main(){
	int n = 3000, c = 11; 
	sd(n);sd(c);
	pw2[0] = 1;
	invpw[0] = 1;
	for(int i = 0; i < (1 << 10); i++){
		sgn[i] = 1 - 2 * ((c - __builtin_popcount(i)) & 1);
	}
	for(int i = 1; i < N; i++){
		pw2[i] = mul(2, pw2[i - 1]);
		invpw[i] = inv(sub(pw2[i], 1));
	}
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		a[i]--;
	}
	for(int i = 1; i <= n; i++){
		memset(freq, 0, sizeof freq);
		int prod = 1;
		int old_prod = 0;
		int num = 0;
		for(int j = i; j >= 1; j--){
			int new_prod = mul(prod, mul(invpw[freq[a[j]]], sub(pw2[freq[a[j]] + 1], 1)));
			if(!freq[a[j]]) num++;
			freq[a[j]]++;
			f[i][j] = num < c ? 0 : sub(new_prod, mul(2, old_prod));
			prod = new_prod;
			if(num==c) old_prod = prod;
		}
		dp[i] = sub(pw2[i], old_prod);
	}
	printf("%d ", sub(dp[n], 1));
	dp[0] = 1;
	int p;
	if(c >= 10){
		for(p = 1; p * c <= n; p++){
			memcpy(old_dp, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			for(int i = p * c; i <= n; i++)
				for(int j = max(1, (p - 1) * c); j <= i; j++){
					dp[i] = add(dp[i], mul(f[i][j], old_dp[j - 1]));
				}
			printf("%d ", dp[n]);
		}
	} else{
		for(p = 1; p * c <= n; p++){
			memset(val, 0, sizeof val);
			memcpy(old_dp, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			for(int i = 1; i <= n; i++){
				// add i
				int k = a[i];
				int sm = 0;
				for(int mask = 0; mask < (1 << c); mask++){
					if(mask >> k & 1){
						val[mask] = mul(2, val[mask]);
					} else{
						val[mask] -= old_dp[i - 1] * sgn[mask];
						val[mask] = fix(val[mask]);
					}
					sm = add(sm, val[mask]);
				}
				dp[i] = sm;
			}
			printf("%d ", dp[n]);
		}
	}
	for(; p <= n; p++) printf("0 ");
		printf("\n");
}