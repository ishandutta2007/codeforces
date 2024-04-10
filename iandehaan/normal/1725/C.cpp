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

constexpr ll mod = 998244353;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll modinv(ll x) {
    return modpow(x, mod-2);
}

#define MAXN 500'000

ll facs[MAXN];

ll choose(ll n, ll m) {
    ll out = facs[n] * modinv(facs[m]);
    out %= mod;
    out *= modinv(facs[n-m]);
    out %= mod;
    return out;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    facs[0] = 1;
    rep(i, 1, MAXN) {
        facs[i] = facs[i-1]*i;
        facs[i] %= mod;
    }

	ll n, k;
	cin >> n >> k;
	ll a[n];
	set<ll> locs;
	locs.insert(0);
	a[0] = 0;
	ll tot = 0;
	rep(i, 1, n) {
		cin >> a[i];
		tot += a[i];
		if (i != 0) a[i] += a[i-1];
		locs.insert(a[i]);
	}
	ll blah;
	cin >> blah;
	tot += blah;

	if (tot % 2 != 0) {
		// k^n
		ll out = 1;
		rep(i, 0, n) {
			out *= k;
			out %= mod;
		}
		cout << out << endl;
		return 0;
	}

	ll x = 0;
	rep(i, 0, n) {
		ll nxtpos = a[i] + tot/2;
		if (locs.count(nxtpos)) {
			x++;
		}
	}
    //cout << x << endl;

    ll out = 0;
    ll prev = 1;
    rep(e, 0, x+1) {
        if (e != 0) {
            prev *= k-e+1; // choose colors
            prev %= mod;

            
        }
        if (e > k) continue;
        if (e == k) {
            if (2*e != n) continue;
        }
        if (e == k-1) {
            if (e != x) continue;
        }
        

        ll med = prev;
            // k - e colors left, color everything except 1 from each thing
            // number of nodes remaining is n - 2*e
            // (x-e) of those must be preserved
            // tot = n - (x-e)-2*e
            // = n - x - e
            med *= modpow(k-e, n - x - e);
            med %= mod;
            med *= modpow(k-e-1, x-e);
        med %= mod;

        // mult by (x choose e)
        med *= choose(x, e);
        med %= mod;



        //cout << e << ' ' << med << endl;
        out += med;
        out %= mod;


    }
    cout << out << endl;

	

	

}