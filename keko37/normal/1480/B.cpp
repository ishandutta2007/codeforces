#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint t, A, B, n;
llint a[MAXN], b[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> A >> B >> n;
        llint sum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum += (b[i] + A - 1) / A * a[i];
        }
        if (sum - mx < B) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}