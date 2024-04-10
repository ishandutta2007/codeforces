#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> sorted = a;
        sort(all(sorted));
        int x = 1, y = n;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            j = max(j, i);
            while (2 * (j - i + 1) < k + n) {
                ++j;
            }
            if (j >= n) {
                break;
            }
            if (y - x > sorted[j] - sorted[i]) {
                x = sorted[i];
                y = sorted[j];
            }
        }
        cout << x << " " << y << "\n";
        vector<int> ans;
        ans.pb(0);
        int bal = 0;
        int delta = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= x && a[i] <= y) {
                ++delta;
            } else {
                --delta;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] >= x && a[i] <= y) {
                ++bal;
            } else {
                --bal;
            }
            if (bal == 1) {
                ans.pb(i);
                --delta;
                if (i == n - 1) {
                    break;
                }
                if (delta == 0) {
                    ans.pop_back();
                    ans.pb(n - 1);
                    break;
                }
                ans.pb(i + 1);
                bal = 0;
            }
        }
        while (sz(ans) > 2 * k) {
            int p = ans.back();
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
            ans.pb(p);
        }
        for (int i = 0; i < sz(ans); i += 2) {
            cout << ans[i] + 1 << " " << ans[i + 1] + 1 << "\n";
        }
    }

}