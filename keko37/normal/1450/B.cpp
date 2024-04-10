#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, k;
int x[MAXN], y[MAXN];

int dist (int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        int ind = -1;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (dist(i, j) <= k) cnt++;
            }
            if (cnt == n) ind = i;
        }
        if (ind == -1) cout << "-1\n"; else cout << "1\n";
    }
    return 0;
}