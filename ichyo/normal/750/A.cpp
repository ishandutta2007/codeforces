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
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    int ans = 0;
    REP(i, n) {
        int c = 5 * (i + 1);
        if(k >= c) {
            k -= c;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}