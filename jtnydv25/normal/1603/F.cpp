#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
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
const int N = 10000007;
int inverses[N];
int powers[N];
const int inv2 = (mod + 1) / 2;

int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	powers[0] = 1;
	for(int i = 1; i < N; i++){
		powers[i] = mul(2, powers[i - 1]);
		inverses[i] = mul_inv(mul(powers[i - 1], powers[i] - 1), mod);
	}
	while(t--){
		int n, k, x; cin >> n >> k >> x;
		if(x == 0){
			if(n > k){
				cout << 0 << endl;
				continue;
			}
			int ans = 1;
			for(int i = 0; i < n; i++){
				ans = mul(ans, sub(powers[k], powers[i]));
			}
			cout << ans << endl;
			continue;
		}
		int ans = 0;
		int coeff = 1;
		int pown = powr(2, n);
		for(int r = 1; r <= min(n, k - 1); r++){
			coeff = mul(coeff, sub(powers[k], powers[r - 1]));
			coeff = mul(coeff, sub(pown, powers[r - 1]));
			coeff = mul(coeff, inverses[r]);
			ans = add(ans, mul(coeff, sub(powers[k], powers[r])));
		}
		cout << add(1, mul(ans, inv(powers[k] - 1))) << endl;
	}
}