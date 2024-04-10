#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
const int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
const int INF = 1e9;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        vector<pair<int, int> > v;
        v.push_back({x1, y1});
        for (int i = 0; i < 9; i++) {
            v.push_back({x2 + dx[i], y2 + dy[i]});
        }
        int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
        for (auto o : v) {
            mnx = min(mnx, o.first);
            mxx = max(mxx, o.first);
            mny = min(mny, o.second);
            mxy = max(mxy, o.second);
        }
        cout << 2 * (mxx - mnx + mxy - mny) << endl;
    }
    
    return 0;
}