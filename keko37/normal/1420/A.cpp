#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;

int t, n;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i - 1] > a[i]) cnt++;
        }
        if (cnt == n - 1) cout << "NO\n"; else cout << "YES\n";
    }
    return 0;
}