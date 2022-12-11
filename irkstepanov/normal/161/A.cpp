#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, m;
    ll x, y;
    cin >> n >> m >> x >> y;

    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    vector<pii> ans;
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        while (ptr < m && b[ptr] < a[i] - x) {
            ++ptr;
        }
        if (ptr == m || b[ptr] > a[i] + y) {
            continue;
        }
        ans.pb({i, ptr});
        ++ptr;
    }
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

}