#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int a[2000];
int c[2000];
int p[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(c, 0, sizeof(c));
        for (int j = 1; j <= 11; j++) {
            for (int i = 1; i <= n; i++) {
                if (!c[i] && a[i] % p[j] == 0) c[i] = j;
            }
        }
        int tot = 0;
        map<int, int> m;
        for (int i = 1; i <= n; i++)
            if (m[c[i]] == 0) m[c[i]] = ++tot;
        cout << m.size() << endl;
        for (int i = 1; i <= n; i++) cout << m[c[i]] << ' ';
        cout << endl;
    }
}