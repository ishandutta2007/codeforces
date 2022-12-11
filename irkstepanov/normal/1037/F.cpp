#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int reduce(ll val) {
    val %= mod;
    if (val < 0) {
        val += mod;
    }
    return val;
}

const int rev2 = (mod + 1) / 2;

int getSum(int a, int b, ll l, ll r) {
    int val = reduce(r * (r + 1) / 2);
    sub(val, reduce(l * (l - 1) / 2));
    mul(val, a);
    int z = reduce(r - l + 1);
    mul(z, b);
    add(val, z);
    return val;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> vct;
    vector<int> lf(n);
    for (int i = 0; i < n; ++i) {
        while (!vct.empty() && a[vct.back()] < a[i]) {
            vct.pop_back();
        }
        if (vct.empty()) {
            lf[i] = -1;
        } else {
            lf[i] = vct.back();
        }
        vct.pb(i);
    }

    vct.clear();
    vector<int> rg(n);
    for (int i = n - 1; i >= 0; --i) {
        while (!vct.empty() && a[vct.back()] <= a[i]) {
            vct.pop_back();
        }
        if (vct.empty()) {
            rg[i] = n;
        } else {
            rg[i] = vct.back();
        }
        vct.pb(i);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int l = lf[i], r = rg[i];
        //cout << i << " " << l << " " << r << endl;
        vector<int> pos;
        pos.pb(0);
        pos.pb((i - 1 - l) / (k - 1));
        pos.pb((r - i - 1) / (k - 1));
        sort(all(pos));
        pos.pb(n);
        for (int j = 0; j + 1 < sz(pos); ++j) {
            if (j + 1 < sz(pos) && pos[j] == pos[j + 1]) {
                continue;
            }
            int t = pos[j] + 1;
            ll x, y, u, v;
            if (t <= (r - i - 1) / (k - 1)) {
                x = 0, y = i;
            } else {
                y = r - 1, x = -k + 1;
            }

            if (t <= (i - 1 - l) / (k - 1)) {
                u = -k + 1, v = i;
            } else {
                u = 0, v = l + 1;
            }

            ll p = x - u, q = v - y;
            //if (i == 1) cout << t << "!" <<  x << " " << y << " " << u << " " << v  << endl;
            ll tl, tr;
            if (p < 0) {
                p *= (-1), q *= (-1);
                if (q <= 0) {
                    tl = tr = -1;
                } else {
                    tl = pos[j] + 1, tr = min(ll(pos[j + 1]), q / p);
                }
            } else if (p == 0) {
                if (q <= 0) {
                    tl = pos[j] + 1, tr = pos[j + 1];
                } else {
                    tl = tr = -1;
                }
            } else {
                if (q <= 0) {
                    tl = pos[j] + 1, tr = pos[j + 1];
                } else {
                    if (q % p) {
                        tl = q / p + 1;
                    } else {
                        tl = q / p;
                    }
                    tl = max(tl, ll(pos[j] + 1));
                    tr = pos[j + 1];
                }
            }

            //cout << i << " " << tl << " " << tr << endl;

            if (tl != -1 && tl <= tr) {
                int val = getSum(reduce(x - u), reduce(y - v + 1), tl, tr);
                mul(val, a[i]);
                add(ans, val);
            }
        }
    }

    cout << ans << "\n";

}