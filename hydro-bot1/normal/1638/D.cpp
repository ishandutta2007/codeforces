// Hydro submission #6251dae7b8869dbad08a04bf@1649531624017
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

const int maxn = 1e3 + 10;
int a[maxn][maxn];

pair<bool,int> check(int x, int y) {
    int t = 0;
    rep(i,x,x+1) rep(j,y,y+1) if(a[i][j]) t = a[i][j];
    rep(i,x,x+1) rep(j,y,y+1) if(a[i][j] && t != a[i][j]) return {false, t};
    return {true, t};
}

bool empty(int x, int y) {
    rep(i,x,x+1) rep(j,y,y+1) if(a[i][j]) return false;
    return true;
}

void reset(int x, int y) {
    rep(i,x,x+1) rep(j,y,y+1) a[i][j] = 0;
}

struct pt { int x, y; };
queue< pt > q;

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, m;
    scanf("%d %d", &n, &m);
    rep(i,1,n) rep(j,1,m) scanf("%d", &a[i][j]);
    rep(i,1,n-1) rep(j,1,m-1)
        if(check(i, j).first)
            q.push({i, j});

    vector< pair<pt, int> > ans;
    while(!q.empty()) {
        pt cur = q.front(); q.pop();
        if(empty(cur.x, cur.y)) continue;
        ans.push_back({cur, check(cur.x, cur.y).second});
        reset(cur.x, cur.y);
        rep(i,max(1, cur.x - 1), min(cur.x + 1, n - 1))
            rep(j,max(1, cur.y - 1), min(cur.y + 1, m - 1))
            if(!empty(i, j) && check(i, j).first)
                q.push({i, j});
    }
    rep(i,1,n) rep(j,1,m) if(a[i][j]) {
        puts("-1"); return 0;
    }
    printf("%zu\n", ans.size());
    for(auto it = ans.rbegin(); it != ans.rend(); ++ it) {
        printf("%d %d %d\n", it -> first.x, it -> first.y, it -> second);
    }
    return 0;
}