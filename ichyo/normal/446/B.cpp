#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long LL;

int main(){
    int h, w;
    while(cin >> h >> w) {
        LL k, p;
        cin >> k >> p;

        LL grid[1001][1001] = {};
        REP(y, h) REP(x, w) {
            cin >> grid[y][x];
        }

        LL row[1001] = {};
        LL col[1001] = {};

        REP(y, h) REP(x, w) row[y] += grid[y][x];
        REP(y, h) REP(x, w) col[x] += grid[y][x];

        priority_queue<LL> rque;
        REP(y, h) rque.push(row[y]);
        vector<LL> rsum;
        rsum.push_back(0);
        REP(_, k) {
            LL rmax = rque.top(); rque.pop();
            rsum.push_back(rsum.back() + rmax);
            rque.push(rmax - w * p);
        }

        priority_queue<LL> cque;
        REP(x, w) cque.push(col[x]);
        vector<LL> csum;
        csum.push_back(0);
        REP(_, k) {
            LL cmax = cque.top(); cque.pop();
            csum.push_back(csum.back() + cmax);
            cque.push(cmax - h * p);
        }

        LL ans = LLONG_MIN;
        REP(i, k + 1) {
            int j = k - i;
            LL sum = rsum[i] + csum[j] - (LL)i * j * p;
            ans = max(ans, sum);
        }

        cout << ans << endl;

    }
    return 0;
}