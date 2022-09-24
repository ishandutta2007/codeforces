#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

const string YES = "YES";
const string NO = "NO";

const int MOD = 998244353;

ll mpow(ll y, ll k) {
    ll res = 1;
    while (k--) res *= y;
    return res;
}

ll root(ll x, int k) {
    ll y = pow(x, 1.0 / k);
    while (mpow(y, k) < x) y++;
    while (mpow(y, k) > x) y--;
    if (mpow(y, k) != x) return -1;
    return y;
}

int solve(vector<ll> a) {
    int n = a.size();
    vector<vector<ll>> b(n);

    for (int i = 0; i < n; i++) {
        for (int k = 4; k >= 2; k--) {
            ll z = root(a[i], k);
            if (z != -1) {
                for (int j = 0; j < k; j++) b[i].push_back(z);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!b[i].empty()) continue;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            ll g = __gcd(a[i], a[j]);
            if (g != 1 && g != a[i]) {
                b[i].push_back(g);
                b[i].push_back(a[i] / g);
                break;
            }
        }
    }

    map<ll, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        if (b[i].empty()) {
            mp1[a[i]]++;
        } else {
            for (ll x : b[i]) {
                mp2[x]++;
            }
        }
    }

    int res = 1;
    for (auto it : mp2) {
        res = 1LL * res * (it.second + 1) % MOD;
    }
    for (auto it : mp1) {
        res = 1LL * res * (it.second + 1) % MOD;
        res = 1LL * res * (it.second + 1) % MOD;
    }
    //cerr << mp1.size() << " " << mp2.size() << endl;
    return res;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (cin >> n) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << solve(a) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}