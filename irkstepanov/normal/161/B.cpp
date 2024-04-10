#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

const ll inf = 1e18;

ll get(vector<vector<pll> >& ans, int cnt) {
    ll sum = 0;
    for (int i = 0; i < sz(ans); ++i) {
        ll minn = inf;
        for (pll p : ans[i]) {
            sum += p.first;
            minn = min(minn, p.first);
        }
        if (i < cnt) {
            sum -= minn / 2;
        }
    }
    return sum;
}

void print(vector<vector<pll> >& ans, int cnt) {
    ll sum = get(ans, cnt);
    cout << sum / 2 << "." << (sum % 2) * 5 << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << sz(ans[i]) << " ";
        for (pll p : ans[i]) {
            cout << p.second + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, k;
    cin >> n >> k;

    vector<pll> a, b;
    for (int i = 0; i < n; ++i) {
        ll x, t;
        cin >> x >> t;
        x *= 2;
        if (t == 1) {
            a.pb({x, i});
        } else {
            b.pb({x, i});
        }
    }

    sort(all(a));
    reverse(all(a));
    sort(all(b));
    reverse(all(b));

    if (sz(a) < k) {
        vector<vector<pll> > ans;
        for (int i = 0; i < sz(a); ++i) {
            ans.pb({a[i]});
        }
        int ptr = 0;
        while (sz(ans) < k - 1) {
            ans.pb({b[ptr]});
            ++ptr;
        }
        ans.pb({});
        while (ptr < sz(b)) {
            ans.back().pb(b[ptr++]);
        }
        print(ans, sz(a));
        return 0;
    }

    vector<vector<pll> > ans;
    for (int i = 0; i < k - 1; ++i) {
        ans.pb({a[i]});
    }
    ans.pb({});
    for (int i = k - 1; i < sz(a); ++i) {
        ans.back().pb(a[i]);
    }
    for (int i = 0; i < sz(b); ++i) {
        ans.back().pb(b[i]);
    }
    print(ans, k);

}