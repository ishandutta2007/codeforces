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

const int nmax = 100500;

int t[2 * nmax];

void update(int pos, int val) {
    pos += nmax;
    t[pos] = max(t[pos], val);
    for (pos >>= 1; pos; pos >>= 1) {
        t[pos] = max(t[pos], val);
    }
}

int get(int l, int r) {
    int ans = 0;
    for (l += nmax, r += nmax; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans = max(ans, t[l]);
        }
        if (!(r & 1)) {
            ans = max(ans, t[r]);
        }
    }
    return ans;
}

vector<int> lis(const vector<int>& a) {
    int n = sz(a);
    vector<int> dp(n);
    memset(t, 0, sizeof(t));
    dp[0] = 1;
    update(a[0], 1);
    for (int i = 1; i < n; ++i) {
        int val = get(0, a[i]);
        dp[i] = val + 1;
        update(a[i], dp[i]);
    }
    return dp;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> val(m);
    //vector<int> cnt(m);
    while (n--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        /*for (int i = l; i <= r; ++i) {
            ++cnt[i];
        }*/
        ++val[l];
        if (r + 1 < m) {
            --val[r + 1];
        }
    }

    for (int i = 1; i < m; ++i) {
        val[i] += val[i - 1];
    }
    /*for (int i = 0; i < m; ++i) {
        assert(val[i] == cnt[i]);
    }*/

    vector<int> a = lis(val);

    vector<int> x = val;
    reverse(all(x));
    vector<int> c = lis(x);
    vector<int> b = c;
    reverse(all(b));

    /*for (int i = 0; i < sz(a); ++i) {
        cout << b[i] << "\n";
    }*/

    int ans = 0;
    for (int i = 0; i < sz(a); ++i) {
        ans = max(ans, a[i] + b[i] - 1);
    }

    cout << ans << "\n";

}