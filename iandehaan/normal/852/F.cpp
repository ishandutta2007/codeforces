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

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

#define MAXN 1001000


ll modpow(ll b, ll e, ll mod) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, q;
    cin >> n >> m >> a >> q;

    // find totient of q
    int qtot = phi(q);

    int order = qtot;
    for (int i = 2; i * i <= qtot; i++) {
        if (qtot % i == 0) {
            // try i and qtot/i
            if (modpow(a, i, q) == 1) {
                order = min(order, i);
            }
            if (modpow(a, qtot/i, q) == 1) {
                order = min(order, qtot/i);
            }
        }
    }
    /*cout << "a = " << a << endl;
    cout << "q = " << q << endl;
    cout << "qtot = " << qtot << endl;
    cout << "order = " << order << endl;*/

    ll fac[MAXN];
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = i * fac[i-1];
        fac[i] %= order;
    }

    ll pref[m+1];
    for (int i = 0; i <= m; i++) {
        // mod inverse of a mod p is a^(p-2)
        // we want (m choose i)
        pref[i] = fac[m];
        //cout << "init = " << pref[i] << endl;
        pref[i] *= modpow(fac[i], order - 2, order);
        
        pref[i] %= order;
        //cout << "nxt1 = " << pref[i] << endl;
        pref[i] *= modpow(fac[m - i], order - 2, order);
        pref[i] %= order;
        if (pref[i] < 0) pref[i] += order;
        //cout << "nxt2 = " << pref[i] << endl;
        //pref[i] = choose(m, i);
        if (i != 0) pref[i] += pref[i-1];
        pref[i] %= order;

        //cout << i << ' ' << pref[i] << endl;
    }

    ll pows[n];

    for (int i = 0; i < n; i++) {
        int distFromRight = n - i - 1;
        if (distFromRight > m) {
            pows[i] = pref[m];
        } else {
            pows[i] = pref[distFromRight];
        }
        
    }


    for (int i = 0; i < n; i++) {
        ll out = modpow(a, pows[i], q);
        out %= q;
        if (out < 0) out += q;
        cout << out << ' ';
    }
    cout << endl;


    
}