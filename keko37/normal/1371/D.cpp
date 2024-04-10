#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 305;

int t, n, k;
int a[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 0;
            }
        }
        int cx = 0, cy = 0;
        for (int i = 0; i < k; i++) {
            a[cx][cy] = 1;
            cx = (cx + 1) % n;
            cy = (cy + 1) % n;
            if (cx == 0) cy = (cy + 1) % n;
        }
        if (k % n == 0) cout << 0 << '\n'; else cout << 2 << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}