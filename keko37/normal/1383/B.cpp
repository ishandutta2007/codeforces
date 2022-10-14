#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
int a[35], b[35];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            for (int j = 0; j <= 30; j++) {
                if (x & (1 << j)) a[j]++; else b[j]++;
            }
        }
        int res = -1;
        for (int i = 30; i >= 0; i--) {
            if (a[i] % 2 == 1) {
                if (a[i] % 4 == 1) res = 1; else res = b[i] % 2;
                break;
            }
        }
        cout << (res == -1 ? "DRAW\n" : (res == 1 ? "WIN\n" : "LOSE\n"));
    }
    return 0;
}