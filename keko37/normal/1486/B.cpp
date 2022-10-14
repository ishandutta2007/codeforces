#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
vector <int> vx, vy;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        vx.clear(); vy.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            vx.push_back(x);
            vy.push_back(y);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        if (n % 2 == 1) {
            cout << 1 << '\n';
        } else {
            cout << ((llint) vx[n/2] - vx[n/2 - 1] + 1) * (vy[n/2] - vy[n/2 - 1] + 1) << '\n';
        }
    }
    return 0;
}