#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t;
llint lef, rig, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> lef >> rig >> m;
        llint lo = m - (rig - lef);
        llint hi = m + (rig - lef);
        for (llint i = lef; i <= rig; i++) {
            llint n = hi / i;
            if (n > 0 && lo <= n * i && n * i <= hi) {
                llint dif = n * i - m;
                if (dif >= 0) {
                    cout << i << " " << lef << " " << lef + dif << '\n';
                } else {
                    cout << i << " " << rig << " " << rig + dif << '\n';
                }
                break;
            }
        }
    }
    return 0;
}