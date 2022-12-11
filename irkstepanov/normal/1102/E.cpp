#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int mod = 998244353;

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

const int nmax = 200500;

int t[2 * nmax];

void upd(int pos, int val) {
    for (pos += nmax; pos; pos >>= 1) {
        t[pos] = max(t[pos], val);
    }
}

int get(int l, int r) {
    int ans = -1;
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> lst;
    for (int i = 0; i < n; ++i) {
        lst[a[i]] = i;
    }

    vector<int> dp(n + 1);


    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        upd(i, lst[a[i]]);
        int g = get(i, lst[a[i]]);
        upd(i, g);
        dp[i] = dp[g + 1];
        if (g != n - 1) {
            mul(dp[i], 2);
        }
    }

    cout << dp[0] << "\n";

}