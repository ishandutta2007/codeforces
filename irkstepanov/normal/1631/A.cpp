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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll val = -1;
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > val) {
                val = a[i];
                pos = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (b[i] > val) {
                val = b[i];
                pos = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (pos == 0 && a[i] < b[i]) {
                swap(a[i], b[i]);
            }
            if (pos == 1 && b[i] < a[i]) {
                swap(a[i], b[i]);
            }
        }
        ll x = -1, y = -1;
        for (int i = 0; i < n; ++i) {
            x = max(x, a[i]);
            y = max(y, b[i]);
        }
        cout << x * y << "\n";
    }

}