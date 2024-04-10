#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    if (n * 2 <= s) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) cout << 2 << " ";
        cout << s - (2 * (n - 1)) << endl;
        cout << 1;
        return 0;
    }
    cout << "NO";
}