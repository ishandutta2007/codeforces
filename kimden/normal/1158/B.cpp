#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;



int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1;
        for (int i = 0; i < n - 1; ++i) {
            cout << 0;
        }
        cout << endl;
        return 0;
    }
    string s(n, '0');
    int t = (n - k) / 2 + 1;
    for (int i = t - 1; i < n; i += t) {
        s[i] = '1';
    }
    cout << s << endl;
//    if (k >= 2 && 3 * k <= n + 4) {
//        for (int i = 0; i < (n - k) / 2; ++i) {
//            cout << 0;
//        }
//        cout << 1;
//        for (int i = 0; i < k - 2; ++i) {
//            cout << 0;
//        }
//        cout << 1;
//        for (int i = 0; i < (n - k) / 2; ++i) {
//            cout << 0;
//        }
//        cout << endl;
//        return 0;
//    }
}