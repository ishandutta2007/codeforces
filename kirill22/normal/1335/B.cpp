#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define yes cout << "YES\n";
#define no cout << "NO\n";

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s(n, 'a');
        for (int i = 0; i < a; i++) {
            if (b > 0) {
                s[i] = 'a' + i;
            }
            else s[i] = s[i - 1];
            b--;
        }
        for (int i = a; i < n; i++) {
            s[i] = s[i - a];
        }
        cout << s << '\n';
    }
}