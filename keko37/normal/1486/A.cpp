#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        llint sum = 0, ok = 1;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            sum += x;
            if (sum < i * (i + 1) / 2) ok = 0;
        }
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}