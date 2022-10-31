// Hydro submission #62526a1c1c2771c2d5176230@1649568288910
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;

const int maxn = 5e5 + 10;
int buc[maxn], top = 0;
vector< pair<int,int> > swp[maxn];
int f[maxn];

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }

    int q; scanf("%d", &q);
    int opt, x, y;
    rep(qr,1,q) {
        scanf("%d", &opt);
        if(opt == 1) {
            scanf("%d", &x);
            buc[ ++ top ] = x;
        } else {
            scanf("%d %d", &x, &y);
            swp[ top ].push_back({x, y});
        }
    }
    rep(i,1,5e5) f[i] = i;
    per(i,top,1) {
        for(auto it = swp[i].rbegin(); it != swp[i].rend(); ++ it)
            f[ it -> first ] = f[it -> second];
        buc[i] = f[buc[i]];
    }
    rep(i,1,top) printf("%d ", buc[i]); puts("");
    return 0;
}