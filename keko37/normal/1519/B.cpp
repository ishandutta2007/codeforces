#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, m, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if (k == n * m - 1) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}