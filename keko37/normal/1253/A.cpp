#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int t, n;
int a[MAXN], b[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int lef = n, rig = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                lef = min(lef, i);
                rig = max(rig, i);
            }
        }
        if (lef == n) {
            cout << "YES\n";
            continue;
        }
        bool moze = 1;
        for (int i = lef; i < rig; i++) {
            if (b[i] <= a[i] || b[i] - a[i] != b[i + 1] - a[i + 1]) {
                moze = 0;
            }
        }
        if (b[rig] <= a[rig]) moze = 0;
        if (moze) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}