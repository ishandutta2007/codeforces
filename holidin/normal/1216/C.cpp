#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

vector <pair<int, int> > v;

int main() {
    int i, j, k, n;
    int xwl, ywl, xwr, ywr;
    int xl[2], xr[2], yl[2], yr[2];
    //freopen("input.txt", "r", stdin);
    cin >> xwl >> ywl >> xwr >> ywr;
    for (i = 0; i < 2; ++i)
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
    for (i = xwl; i < xwr; ++i) {
        vector <pair<int, int> > vp;
        vp.push_back({ywl, 0});
        vp.push_back({ywr, 0});
        bool is = 0;
        int f = 0;
        for (j = 0; j < 2; ++j)
        if (xl[j] <= i && xr[j] > i) {
            vp.push_back({yl[j], 1});
            vp.push_back({yr[j], -1});
        }
        sort(vp.begin(), vp.end());
        int balance = 0;
        while (f < vp.size()) {
            j = f;
            while (j < vp.size() && vp[j].fi == vp[f].fi) {
                if (vp[j].se == 0)
                    is ^= 1;
                else
                    balance += vp[j].se;
                ++j;
            }
            if (is && balance == 0) {
                cout << "YES";
                exit(0);
            }
            f = j;
        }
    }
    cout << "NO";
}