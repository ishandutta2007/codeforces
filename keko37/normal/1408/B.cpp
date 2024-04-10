#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, k;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int br = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1 && a[i] != a[i - 1]) br++;
        }
        if (k == 1) {
            if (br == 0) cout << "1\n"; else cout << "-1\n";
        } else {
            cout << max(1, (br + k - 2) / (k - 1)) << '\n';
        }
    }
    return 0;
}