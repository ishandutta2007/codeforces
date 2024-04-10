#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> ans;
    for (int k = 1; k <= n; ++k) {
        vector<ll> x(k);
        vector<bool> was(k, false);
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            int val = a[i] - a[i - 1];
            int pos = (i - 1) % k;
            if (!was[pos]) {
                x[pos] = val;
                was[pos] = true;
            } else if (x[pos] != val) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.pb(k);
        }
    }

    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}