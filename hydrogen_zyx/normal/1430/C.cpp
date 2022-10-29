#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool cmp(int a, int b) { return a > b; }
int a[200005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2 << endl;
        if (n >= 3) {
            cout << n << ' ' << n - 2 << endl;
            cout << n - 1 << ' ' << n - 1 << endl;
            for (int i = n - 1; i >= 3; i--) cout << i << ' ' << i - 2 << endl;
        } else {
            cout << 1 << ' ' << 2 << endl;
        }
    }
}