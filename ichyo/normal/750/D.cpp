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

inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int DR = 8;
const int MX = 160;
const int MN = 30;
bool memo[2*MX+1][2*MX+1][MN][DR];
bool answer[2*MX+1][2*MX+1];
int N;
int t[MN];
void dfs(int cx, int cy, int level, int dir) {
    if(level == N) return;
    if(memo[cx+MX][cy+MX][level][dir]) return;
    memo[cx+MX][cy+MX][level][dir] = true;
    answer[cx+MX][cy+MX] = true;
    REP(_, t[level]) {
        cx += dx[dir];
        cy += dy[dir];
        answer[cx+MX][cy+MX] = true;
    }
    dfs(cx, cy, level+1, (dir+1)%DR);
    dfs(cx, cy, level+1, (dir-1+DR)%DR);
}

int main(){
    iostream_init();
    cin >> N;
    REP(i, N) cin >> t[i];
    t[0]--;
    dfs(0, 0, 0, 2);
    int ans = 0;
    REP(i, 2*MX+1) REP(j, 2*MX+1) if(answer[i][j]) ans++;
    cout << ans << endl;
    return 0;
}