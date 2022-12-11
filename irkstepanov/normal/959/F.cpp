#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <random>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int mod = 1e9 + 7;

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

const int rmax = 20;

vector<int> gauss(vector<int> a) {
    int done = 0;
    int n = sz(a);
    for (int j = rmax - 1; j >= 0; --j) {
        int f = -1;
        for (int i = done; i < n; ++i) {
            if (bit(a[i], j)) {
                f = i;
                break;
            }
        }
        if (f == -1) {
            continue;
        }
        swap(a[done], a[f]);
        f = done;
        ++done;
        for (int i = f + 1; i < n; ++i) {
            if (bit(a[i], j)) {
                a[i] ^= a[f];
            }
        }
    }
    while (sz(a) > 0 && a.back() == 0) {
        a.pop_back();
    }
    return a;
}

bool obt(int val, const vector<int>& a) {
    int ptr = rmax - 1;
    for (int i = 0; i < sz(a); ++i) {
        while (!bit(a[i], ptr)) {
            --ptr;
        }
        if (bit(val, ptr)) {
            val ^= a[i];
        }
    }
    return val == 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pii> > queries(n);
    for (int i = 0; i < q; ++i) {
        int pos, x;
        cin >> pos >> x;
        --pos;
        queries[pos].pb({i, x});
    }

    vector<int> ans(q);

    vector<int> basis;
    for (int i = 0; i < n; ++i) {
        basis.pb(a[i]);
        basis = gauss(basis);
        for (pii p : queries[i]) {
            if (obt(p.second, basis)) {
                ans[p.first] = binpow(2, i + 1 - sz(basis));
            } else {
                ans[p.first] = 0;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }

}