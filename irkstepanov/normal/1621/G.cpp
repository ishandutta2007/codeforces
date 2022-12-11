#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

vector<int> t;
int N;

int get(int l, int r) {
    int ans = 0;
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            add(ans, t[l]);
        }
        if (!(r & 1)) {
            add(ans, t[r]);
        }
    }
    return ans;
}

void update(int pos, int val) {
    for (pos += N; pos; pos >>= 1) {
        add(t[pos], val);
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

vector<int> a;

vector<int> solve(vector<int> posit) {
    vector<pii> sorted;
    for (int i = 0; i < sz(posit); ++i) {
        sorted.pb({a[posit[i]], i});
    }
    sort(all(sorted), [&] (pii u, pii v) {
       if (u.first != v.first) {
            return u.first > v.first;
         }
         return u.second < v.second;
    });
    N = sz(sorted);
    t.assign(2 * N, 0);
    vector<int> ans(N);
    for (int i = 0; i < sz(sorted); ++i) {
        int pos = sorted[i].second;
        int val = get(pos + 1, N - 1);
        if (i == 0) add(val, 1);
        ans[pos] = val;
        update(pos, val);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<pii> sorted;
        for (int i = 0; i < n; ++i) {
            sorted.pb({a[i], i});
        }
        sort(all(sorted), [&] (pii u, pii v) {
           if (u.first != v.first) {
                return u.first < v.first;
             }
             return u.second > v.second;
        });
        N = n;
        t.assign(2 * N, 0);
        vector<int> dp(n);
        for (int i = 0; i < sz(sorted); ++i) {
            int pos = sorted[i].second;
            int val = get(0, pos - 1);
            add(val, 1);
            dp[pos] = val;
            update(pos, val);
        }

        reverse(all(sorted));
        t.assign(2 * N, 0);
        vector<int> dp3(n, -1);
        vector<int> suff(n + 1);
        suff[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = max(suff[i + 1], a[i]);
        }
        int r = 0;

        vector<vector<int> > posit(n);

        for (int i = 0; i < sz(sorted); ++i) {
            int pos = sorted[i].second;
            while (r + 1 <= n && suff[r + 1] > a[pos]) {
                ++r;
            }
            if (r <= pos || suff[r] <= a[pos]) {
                //cout << "!" << pos << " " << r << endl;
                dp3[pos] = -1;
                continue;
            }
            posit[r].pb(pos);
        }

        vector<int> dp2(n);
        t.assign(2 * N, 0);
        for (int i = 0; i < sz(sorted); ++i) {
            int pos = sorted[i].second;
            int val = get(pos + 1, n - 1);
            add(val, 1);
            dp2[pos] = val;
            update(pos, val);
        }

        for (int j = 0; j < n; ++j) {
            if (posit[j].empty()) {
                continue;
            }
            posit[j].pb(j);
            sort(all(posit[j]));
            vector<int> vct = solve(posit[j]);
            for (int i = 0; i < sz(vct) - 1; ++i) {
                dp3[posit[j][i]] = vct[i];
            }
        }

        /*for (int i = 0; i < n; ++i) {
            cout << dp3[i] << " ";
        }
        cout << "\n";*/

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dp3[i] == -1) {
                continue;
            }
            int x = dp2[i];
            sub(x, dp3[i]);
            mul(x, dp[i]);
            //cout << dp[i] << " " << dp2[i] << " " << dp3[i] << endl;
            add(ans, x);
        }
        cout << ans << "\n";
    }

}