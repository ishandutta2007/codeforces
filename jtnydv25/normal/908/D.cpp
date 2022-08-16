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

const int mod = 1e9 + 7;
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

const int N = 1005;
int dp[N][N];

int main(){
	int pa, pb, k;
	sd(k); sd(pa); sd(pb); 
	int p = mul(pb, inv(pa + pb));
	int q = sub(1, p);
	for(int i = 1; i <= k; i++){
		dp[k][i] = add(k - 1, mul(1, inv(p)));
		for(int curra = k - 1; curra >= 1; curra--){
			dp[curra][i] = mul(q, dp[curra + 1][i]);
			if(curra >= i){
				dp[curra][i] = add(dp[curra][i], mul(p, curra));
			} else{
				dp[curra][i] = add(dp[curra][i], mul(p, add(dp[curra][i - curra], curra)));
			}
		}

	}
	printf("%d\n", dp[1][k]);
}