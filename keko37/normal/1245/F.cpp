#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 35;

int t, lef, rig;
int a, b;
llint dp[2][2][MAXN];

llint calc (int pa, int pb, int pos) {
    if (pos == -1) return 1;
    if (dp[pa][pb][pos] != -1) return dp[pa][pb][pos];
    llint res = 0;
    int ca = !!(a & (1 << pos));
    int cb = !!(b & (1 << pos));
    for (int za = 0; za <= 1; za++) {
        for (int zb = 0; zb <= 1; zb++) {
            if (za == 1 && zb == 1) continue;
            if (pa == 1 && za > ca) continue;
            if (pb == 1 && zb > cb) continue;
            res += calc(pa & (za == ca), pb & (zb == cb), pos - 1);
        }
    }
    return dp[pa][pb][pos] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> lef >> rig;
        if (lef == 0) {
            memset(dp, -1, sizeof dp); a = rig; b = rig;
            cout << calc(1, 1, 31) << endl;
        } else {
            llint val[3];
            memset(dp, -1, sizeof dp); a = rig; b = rig;
            val[0] = calc(1, 1, 31);
            memset(dp, -1, sizeof dp); a = lef - 1; b = rig;
            val[1] = calc(1, 1, 31);
            memset(dp, -1, sizeof dp); a = lef - 1; b = lef - 1;
            val[2] = calc(1, 1, 31);
            //cout << "bla " << val[0] << " " << val[1] << " " << val[2] << endl;
            cout << val[0] - 2 * val[1] + val[2] << endl;
        }
    }
    return 0;
}