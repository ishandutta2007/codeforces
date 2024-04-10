// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define error(args...) 
#endif

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

int main(){
    iostream_init();
    int n;
    cin >> n;

    vector<LL> c(n);
    vector<int> d(n);
    REP(i, n) cin >> c[i] >> d[i];

    LL A = LLONG_MIN;
    LL B = LLONG_MAX;

    LL cur = 0;
    REP(i, n) {
        if(d[i] == 1) {
            A = max(A, 1900LL - cur);
        } else {
            B = min(B, 1899LL - cur);
        }
        cur += c[i];
    }

    if(A > B) {
        cout << "Impossible" << endl;
    } else if(B == LLONG_MAX) {
        cout << "Infinity" << endl;
    } else {
        cout << B + cur << endl;
    }

    return 0;
}