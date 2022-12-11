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
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

//typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef int ll;
//typedef pair<ll, ll> pll;
typedef double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

vector<ll> lf, rg;
int n;

struct ddata {
    int i;
    ll x;
};

struct segment {
    ll l;
    ll r;
    int id;
    bool operator<(const segment& other) const {
        return l < other.l;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int P;
    cin >> n >> P;

    lf.resize(n), rg.resize(n);
    vector<ll> t(n);

    for (int i = 0; i < n; ++i) {
        cin >> lf[i];
        ll x;
        cin >> x;
        rg[i] = lf[i] + x - 1;
        cin >> t[i];
    }

    vector<ll> dp(1 << n, -1);
    vector<ddata> p(1 << n);
    dp[0] = 1;

    vector<segment> segs(n);
    for (int i = 0; i < n; ++i) {
        segs[i] = {lf[i], rg[i], i};
    }
    sort(all(segs));

    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == -1) {
            continue;
        }

        ll init = dp[mask];
        int ptr = 0;
        while (ptr < n && segs[ptr].r < init) {
            ++ptr;
        }
        int init_ptr = ptr;

        for (int i = 0; i < n; ++i) {
            if (bit(mask, i)) {
                continue;
            }
            ll x = dp[mask];
            ptr = init_ptr;
            bool ax = true;
            bool ay = true;
            while (ptr < n && (ax || ay)) {
                int j = segs[ptr].id;
                if (bit(mask, j) && !(rg[j] < x || lf[j] > x + t[i])) {
                    x = rg[j] + 1;
                } else if (bit(mask, j)) {
                    ax = false;
                }
                if (!bit(mask, j) && lf[j] <= x && rg[j] >= x) {
                    x = rg[j] + 1;
                } else if (!bit(mask, j)) {
                    ay = false;
                }
                ++ptr;
            }
            if (lf[i] <= x + t[i]) {
                continue;
            }
            if (dp[mask | (1 << i)] == -1 || dp[mask | (1 << i)] > x + t[i]) {
                dp[mask | (1 << i)] = x + t[i];
                p[mask | (1 << i)] = {i, x};
            }
        }
    }

    if (P == 1) {
        if (dp[(1 << n) - 1] == -1) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        int mask = (1 << n) - 1;
        vector<ll> ans(n);
        while (mask) {
            ddata d = p[mask];
            ans[d.i] = d.x;
            mask ^= (1 << d.i);
        }
        for (int i = 0; i < n; ++i) {
            cout << "1 " << ans[i] << "\n";
        }
        return 0;
    }

    int res = -1;

    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] != -1 && dp[((1 << n) - 1) ^ mask] != -1) {
            res = mask;
        }
    }

    if (res == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<ddata> ans(n);
    vector<int> vct = {res, ((1 << n) - 1) ^ res};
    int y = 0;
    for (int m : vct) {
        ++y;
        int mask = m;
        while (mask) {
            ddata d = p[mask];
            //cout << "!" << mask << " " << d.i << endl;
            ans[d.i] = {y, d.x};
            mask ^= (1 << d.i);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i].i << " " << ans[i].x << "\n";
    }

}