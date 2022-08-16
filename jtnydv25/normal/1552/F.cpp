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
#define endl '\n'
#endif
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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> x(n + 1), y(n), s(n);
	vector<int> fst(n + 1);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];
	x[n] = x[n - 1] + 1;
	vector<int> dp(n);
	vector<int> sdp(n);
	for(int i = 0; i < n; i++){
		int j = upper_bound(all(x), y[i]) - x.begin();
		dp[i] = add(sub((i == 0 ? 0 : sdp[i - 1]), j == 0 ? 0 : sdp[j - 1]), x[i + 1] - x[i]);
		dp[i] = add(dp[i], sub(x[j], y[i]));
		sdp[i] = add(i == 0 ? 0 : sdp[i - 1], dp[i]);
	}
	// trace(dp);
	int cur = 0;
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans = add(ans, sub(x[i], cur));
		if(i != n && s[i]){
			ans = add(ans, dp[i]);
			ans = sub(ans, sub(x[i + 1], x[i]));
		}
		cur = x[i];
	}
	cout << ans << endl;
}