#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n, lef, rig;
int col[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> lef >> rig;
        for (int i = 1; i <= n; i++) col[i] = 0;
        for (int i = 1; i <= n; i++) {
            int c; cin >> c;
            if (i <= lef) col[c]++; else col[c]--;
        }
        int sum_lef = 0, sum_rig = 0, a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (col[i] < 0) {
                sum_lef += -col[i];
                if ((-col[i]) % 2 == 1) a++;
            } else {
                sum_rig += col[i];
                if (col[i] % 2 == 1) b++;
            }
        }
        if (a > sum_rig) {
            cout << a + (sum_lef - a) / 2 << '\n';
        } else if (b > sum_lef) {
            cout << b + (sum_rig - b) / 2 << '\n';
        } else {
            cout << (sum_lef + sum_rig) / 2 << '\n';
        }
    }
    return 0;
}