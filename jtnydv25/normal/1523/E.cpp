#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

const int N = 2e6 + 10, mod = 1e9 + 7;
int fact[N], invfact[N], p2[N], invp2[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
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
void pre(){
	fact[0] = invfact[0] = p2[0] = invp2[0] = 1;
	for(int i = 1;i < N; i++){
		fact[i] = mul(i, fact[i - 1]);
		p2[i] = mul(2, p2[i - 1]);
		invp2[i] = mul(invp2[i - 1], (mod + 1) >> 1);
	}
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}

inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	pre();
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int ans = 2;
		for(int t = 2; t <= n; t++){
			int r = n - 1 - k * (t - 1);
			if(r < 0) break;
			ans = add(ans, mul(C(r + t, t), inv(C(n, t))));
		}
		cout << ans << endl;
	}
}