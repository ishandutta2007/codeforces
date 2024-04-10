#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
char c[300000];
char a[300000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> c + 1;
        memset(a, 0, sizeof(a));
        cin >> n;
        int len = strlen(c + 1);
        for (int i = 1; i <= len; i++) {
            if (c[i] == '0') {
                if (i - n >= 1) a[i - n] = '0';
                if (i + n <= len) a[i + n] = '0';
            }
        }
        bool f = 1;
        for (int i = 1; i <= len; i++) {
            if (c[i] == '1') {
                char l, r;
                l = (i - n >= 1 ? a[i - n] : '0');
                r = (i + n <= len ? a[i + n] : '0');
                if (l == '0' && r == '0') f = 0;
            }
        }
        if (!f) {
            cout << -1 << endl;
        } else {
            for (int i = 1; i <= len; i++) {
                if (a[i] == '0')
                    cout << 0;
                else
                    cout << 1;
            }
            cout << endl;
        }
    }
}