#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define N 1000010

int b[N];

int QB(int i) {
    int r = 0;
    for (i++; i > 0; i -= i&-i) r += b[i];
    return r;
}

void ub(int i, int r) {
    for (i++; i < N; i += i&-i) b[i] += r;
}

int cnt[N];
vector<int> ax;

int cpr(int x) {
    //printf("x=%d\n", x);
    int ans = lower_bound(ax.begin(),ax.end(),x)-ax.begin();
    //printf("ans=%d\n", ans);
    return ans;
}

int qb(int x) {
    return QB(cpr(x));
}

void addx(int x, int v) {
    x = cpr(x);
    if (cnt[x]) ub(x, -1);
    cnt[x] += v;
    if (cnt[x]) ub(x, 1);
}

tuple<int,int,int,int> ev[N*2];
int n;
int ne;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1>x2) swap(x1,x2);
        if (y1>y2) swap(y1,y2);
        if (x1 == x2) {
            // add
            ev[ne++] = make_tuple(y1, 0, x1, x2);
            // rem
            ev[ne++] = make_tuple(y2+1, 1, x1, x2);
        } else {
            // query
            ev[ne++] = make_tuple(y1, 2, x1, x2);
        }
        ax.push_back(x1);
        ax.push_back(x2);
        ax.push_back(x1-1);
        ax.push_back(x2+1);
    }
    int inf = 1e9+10;
    ax.push_back(inf);
    sort(ax.begin(),ax.end());
    ax.resize(unique(ax.begin(),ax.end())-ax.begin());
    sort(ev,ev+ne);
    long long res = 0;
    int prv = -inf;
    int lxq = -inf;
    FO(i,0,ne) {
        auto &e = ev[i];
        int y, t, x1, x2;
        tie(y,t,x1,x2) = e;
        res += (y-prv) * 1ll * qb(inf);
        if (y != prv) lxq = -inf;
        //printf("res=%lld\n", res);
        if (t == 0) {
            // add
            addx(x1, 1);
        } else if (t == 1) {
            // remove
            addx(x1, -1);
        } else if (t == 2) {
            // query
            x1 = max(x1, lxq+1);
            if (x1 <= x2) {
                res += x2-x1+1;
                res -= qb(x2) - qb(x1-1);
            }
            lxq = max(lxq, x2);
            //printf("QUERY\n");
        }
        prv = y;
        //printf("res=%lld\n", res);
    }
    printf("%lld\n", res);
}