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
        int a[3];
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 9 != 0) {
            cout << "No" << endl;
            continue;
        }
        sort(a, a + 3);
        for (int i = 0; i < 3; ++i) {
            a[i] -= sum / 9;
        }
        if (a[0] < 0) {
            cout << "No" << endl;
            continue;
        }
        if (a[1] < 0) {
            cout << "No" << endl;
            continue;
        }
        if (a[2] < 0) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }




}