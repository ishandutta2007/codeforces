#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int kmax = 6;

vector<ll> h;

struct Number {
    ll m[kmax];
    Number() {
        memset(m, 0, sizeof(m));
    }
    Number(ll val) {
        memset(m, 0, sizeof(m));
        m[0] = val % ll(1e9);
        m[1] = val / ll(1e9);
    }
    void shift(int k) {
        for (int i = kmax - 1; i >= 0; --i) {
            if (i - k >= 0) {
                m[i] = m[i - k];
            } else {
                m[i] = 0;
            }
        }
    }
    Number operator+(const Number& other) const {
        Number ans;
        ll c = 0;
        for (int i = 0; i < kmax; ++i) {
            c += m[i] + other.m[i];
            ans.m[i] = c % ll(1e9);
            c /= ll(1e9);
        }
        return ans;
    }
    Number operator*(ll val) const {
        Number ans;
        ll c = 0;
        for (int i = 0; i < kmax; ++i) {
            c += m[i] * val;
            ans.m[i] = c % ll(1e9);
            c /= ll(1e9);
        }
        return ans;
    }
    Number operator*(const Number& other) const {
        Number ans;
        for (int i = 0; i < kmax; ++i) {
            Number t = *this * other.m[i];
            t.shift(i);
            ans = ans + t;
        }
        return ans;
    }
    bool operator<(const Number& other) const {
        for (int i = kmax - 1; i >= 0; --i) {
            if (m[i] != other.m[i]) {
                return m[i] < other.m[i];
            }
        }
        return false;
    }
};

map<pll, ll> c;
map<pll, ll> cr;
map<ll, int> x, y;
ll a0;

int ans = 0;

void ok(ll x) {
    Number res;
    int posit = 0;
    for (auto it : y) {
        ll z = c[{a0, it.first}];
        if (z % x) {
            return;
        }
        ll b = z / x;
        if (h[posit] % b) {
            return;
        }
        ++posit;
    }
    ++ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cntx = 0, cnty = 0;

    for (int i = 0; i < n; ++i) {
        ll a, b, cnt;
        cin >> a >> b >> cnt;
        if (!x.count(a)) {
            x[a] = cntx++;
        }
        if (!y.count(b)) {
            y[b] = cnty++;
        }
        c[{a, b}] = cnt;
    }

    if (cntx < cnty) {
        map<pll, ll> tmp;
        swap(x, y);
        for (auto it : c) {
            tmp[{it.first.second, it.first.first}] = it.second;
        }
        swap(c, tmp);
    }

    for (auto it : c) {
        cr[{it.first.second, it.first.first}] = it.second;
    }

    map<pll, ll>::iterator iter = cr.begin();
    while (iter != cr.end()) {
        h.pb(0);
        ll x = iter->first.first;
        while (iter != cr.end() && iter->first.first == x) {
            h.back() = __gcd(h.back(), iter->second);
            ++iter;
        }
    }

    for (auto a : x) {
        for (auto b : y) {
            if (!c.count({a.first, b.first})) {
                cout << "0\n";
                return 0;
            }
        }
    }
    a0 = x.begin()->first;
    ll b0 = y.begin()->first;

    ll val = c[{a0, b0}];

    for (ll x = 1; x * x <= val; ++x) {
        if (val % x == 0) {
            ok(x);
            if (x * x != val) {
                ok(val / x);
            }
        }
    }

    cout << ans << "\n";


}