#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    vector<int> ans(n, -1);
    int put = 0;
    int val = n;
    while (put < n) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0 && r[i] == 0 && ans[i] == -1) {
                ok = true;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0 && r[i] == 0 && ans[i] == -1) {
                ans[i] = val;
                ++put;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] != val) {
                continue;
            }
            for (int j = 0; j < i; ++j) {
                if (ans[j] == -1) {
                    --r[j];
                    if (r[j] < 0) {
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
            for (int j = i + 1; j < n; ++j) {
                if (ans[j] == -1) {
                    --l[j];
                    if (l[j] < 0) {
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
        --val;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
}