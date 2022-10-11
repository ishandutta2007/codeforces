//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int lg = 20;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, p[maxn], cnt[maxn][lg];
ll f[maxn], fp[maxn], ans;

int C(int a, int b){
	if(a < 0 || b < 0 || a - b < 0) return 0;
	return f[a] * fp[b] % mod * fp[a - b] % mod;
}

int main(){
	fast_io;
	f[0] = fp[0] = 1;
	for(int i = 1; i < maxn; i++){
		f[i] = f[i - 1] * i % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	for(int i = 2; i < maxn; i++){
		if(p[i]) continue;
		p[i] = i;
		if(i < 10000){
			for(int j = i * i; j < maxn; j += i){
				p[j] = i;
			}
		}
	}
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		while(x != 1){
			int y = p[x], c = 0;
			while(x % y == 0){
				x /= y;
				c++;
			}
			cnt[y][c]++;
		}
	}
	for(int i = 2; i < maxn; i++){
		if(p[i] != i) continue;
		cnt[i][0] = n;
		for(int j = 1; j < lg; j++){
			cnt[i][0] -= cnt[i][j];
		}
		if(cnt[i][0] == n) continue;
		int cn = n;
		for(int j = 0; j < lg; j++){
			cn -= cnt[i][j];
			ll ps1 = pw(2, n - cn), ps2 = 0;
			for(int k = 0; k <= cn; k++){
				ps1 += mod - C(n - cn, k);
				if(ps1 >= mod) ps1 -= mod;
			}
			for(int k = cn; k >= 0; k--){
				ps1 += C(n - cn, k);
				if(ps1 >= mod) ps1 -= mod;
				ans = (ans + (ps1 * C(cn, k) + ps2 * C(n - cn, k)) % mod * k) % mod;
				ps2 += C(cn, k);
				if(ps2 >= mod) ps2 -= mod;
			}
		}
	}
	cout << ans;
	
	return 0;
}