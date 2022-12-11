#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    if (k > n) {
        cout << "NO\n";
        return 0;
    }

    vector<int> ans(n);
    int color = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt;
        if (cnt > k) {
            cout << "NO\n";
            return 0;
        }
        ans[a[i].second] = color;
        color = (color + 1) % k;
        if (i + 1 < n && a[i].first != a[i + 1].first) {
            cnt = 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

}