#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a) {
	if (a.empty()) return {};
	int s = sz(a) + sz(a) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), out(n);
	L.resize(n);
	ntt(L);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * L[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, f;
    cin >> n >> k >> f;

    vl vec(k+1, 1);
    vl sm(3*(k+1));

    rep(i, 0, n) {
        vec = conv(vec);
        
        
        if (i != n-1) {
            int m = sz(vec);
            
            for (int ind = m-1; ind >= 0; ind--) {
                sm[ind] = vec[ind];
                if (ind < m-1) sm[ind] += sm[ind+1];
                sm[ind] %= mod;
            }
            rep(ind, 0, k+1) {
                // (k-ind) ways to set my current position, forcing my children to cut it off
                vec[ind] = (((k-ind)*vec[ind])+sm[ind]) % mod;
            }
            vec.resize(k+1);
        }
        //for (ll x : vec) cout << x << ' ';
        //cout << endl;

    }
    if (sz(vec) >= f+1) cout << vec[f] << endl;
    else cout << 0 << endl;
}