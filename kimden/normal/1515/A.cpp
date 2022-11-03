#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(rall(a));
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                for (int j = n - 1; j > i; --j) {
                    swap(a[j], a[j - 1]);
                }
                if (a[i] == x) {
                    ok = false;
                    break;
                }
            }
            x -= a[i];
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                if (i)
                    cout << " ";
                cout << a[i];
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }



}