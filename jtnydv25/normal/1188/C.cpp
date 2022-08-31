#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
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

const int N = 1005;
const int MAX = 100005;
int dp[N][N], dp2[N][N];
int a[N];
const int mod = 998244353;
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
int mn_ind[N];

int get(int delta, int k, int n){
	int mx = min(n, (MAX / delta + 1));
	dp[0][0] = 1;
	for(int j = 1; j <= n; j++) dp[0][j] = 0;
	for(int i = 1; i <= n; i++){
		while(mn_ind[i] > 0 && a[i] - a[mn_ind[i]] < delta) mn_ind[i]--;
		int z = mn_ind[i];
		dp[i][0] = 1;
		for(int j = 1; j <= mx; j++){
			dp[i][j] = add(dp[i - 1][j], dp[z][j - 1]);
			// steps++;
		}
	}
	return k <= mx ? dp[n][k] : 0;
}

int main(){
	int n = 1000, k = 500;
	sd(n); sd(k);

	for(int i = 1; i <= n; i++){
		a[i] = rand() % MAX;
		sd(a[i]);
		mn_ind[i] = i - 1;
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int j = 1; j < MAX; j++){
		ans = add(ans, get(j, k, n));
	}
	printf("%d\n", ans);
}