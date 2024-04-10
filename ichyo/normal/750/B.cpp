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
    int cur = 0;
    const int D = 20000;
    bool ans = true;
    REP(i, n) {
        int len;
        string dir;
        cin >> len >> dir;
        if(dir[0] != 'S' && dir[0] != 'N') {
            if(cur == 0 || cur == D) {
                ans = false;
                // break;
            }
        }
        if(dir[0] == 'S') {
            cur += len;
            if(cur > D) {
                ans = false;
                // break;
            }
        }
        if(dir[0] == 'N') {
            cur -= len;
            if(cur < 0) {
                ans = false;
                // break;
            }
        }
    }
    if(cur != 0) ans = false;
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}