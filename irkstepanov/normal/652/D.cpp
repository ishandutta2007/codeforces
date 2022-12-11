#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

vector<vector<int> > t;

vector<int> merge(const vector<int>& p, const vector<int>& q)
{
    int a = 0, b = 0;
    vector<int> ans;
    for (; a < sz(p) && b < sz(q); ) {
        if (p[a] < q[b]) {
            ans.pb(p[a]);
            ++a;
        } else {
            ans.pb(q[b]);
            ++b;
        }
    }
    for (; a < sz(p); ++a) {
        ans.pb(p[a]);
    }
    for (; b < sz(q); ++b) {
        ans.pb(q[b]);
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<int> sorted;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        sorted.pb(x[i]);
        sorted.pb(y[i]);
    }
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    t.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        x[i] = lower_bound(all(sorted), x[i]) - sorted.begin();
        y[i] = lower_bound(all(sorted), y[i]) - sorted.begin();
        t[2 * n + x[i]] = {y[i]};
    }
    for (int i = 2 * n - 1; i; --i) {
        t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }

    for (int i = 0; i < n; ++i) {
        int l = x[i] + 2 * n, r = y[i] + 2 * n;
        int cnt = 0;
        for (; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                cnt += lower_bound(all(t[l]), y[i]) - t[l].begin();
            }
            if (!(r & 1)) {
                cnt += lower_bound(all(t[r]), y[i]) - t[r].begin();
            }
        }
        cout << cnt << "\n";
    }

}