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

const ll inf = 5e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll t;
    cin >> t;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
        if (x[i] < i) {
            cout << "No\n";
            return 0;
        }
    }

    vector<int> pref(n);
    vector<ll> lb(n), ub(n, inf);
    for (int i = 0; i < n; ++i) {
        lb[i] = a[i] + t;
    }
    for (int i = 0; i < n; ++i) {
        ++pref[i];
        --pref[x[i]];
        if (x[i] < n - 1) {
            ub[x[i]] = a[x[i] + 1] + t - 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pref[i];
        if (sum) {
            lb[i] = a[i + 1] + t;
        }
    }

    vector<ll> b(n);
    ll prev = -inf;
    for (int i = 0; i < n; ++i) {
        if (lb[i] > ub[i]) {
            cout << "No\n";
            return 0;
        }
        b[i] = max(lb[i], prev + 1);
        prev = b[i];
        if (b[i] > ub[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";

}