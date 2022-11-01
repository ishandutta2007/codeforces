#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

const int MOD = 1000000000 + 7;
inline void add(int& x, int y) {
    x = x + y;
    while(x >= MOD) x -= MOD;
}
inline void sub(int& x, int y) {
    x = x - y;
    while(x < 0) x += MOD;
}

int main(){
    int n, a, b, k;
    while(cin >> n >> a >> b >> k) {
        a--; b--;
        if(a > b) {
            a = n - 1 - a;
            b = n - 1 - b;
        }
        // 0 .. a .. b - 1
        n = b;
        int dp[2][5050] = {};
        int*cur = dp[0], *next = dp[1];
        REP(i, n) cur[i] = (i >= a ? 1 : 0);
        REP(_, k) {
            REP(i, n) next[i] = 0;
            int prev = 0;
            REP(i, n) {
                int ub = i + (n - i - 1) / 2;
                add(next[i], (ub < 0 ? 0 : cur[ub]));
                sub(next[i], cur[i]);
                if(i-1 >= 0) add(next[i], cur[i-1]);
                add(next[i], prev);
                prev = next[i];
            }
            //REP(i, n) cout << next[i] << " "; cout << endl;
            swap(cur, next);
        }
        cout << cur[b - 1] << endl;
    }
    return 0;
}