#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) cout << 9 << endl;
        else if (n == 2) cout << 98 << endl;
        else {
            n--;
            cout << 9;
            int now = 8;
            for (int i = 0; i < n; i++) {
                cout << now;
                now++;
                now %= 10;
            }
            cout << endl;
        }
    }
}