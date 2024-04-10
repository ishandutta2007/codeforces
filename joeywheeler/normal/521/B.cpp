#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

map<pair<int,int>,int> s;
pair<int,int> pos[100005];
set<tuple<int,int,int> > ord;
int n; 

int res[100005], ri;

bool danger(int x, int y) {
    if (!s.count({x,y})) return false;
    int t = 0;
    for (int nx = x-1; nx <= x+1; nx++) t += s.count({nx,y-1});
    return t == 1;
}

bool shouldbe(int i, pair<int,int> p, bool ins = true) {
    if (ord.count(tuple<int,int,int>(i,p.first,p.second))) return false;
    int x, y;
    tie(x,y) = p;
    for (int nx = x-1; nx <= x+1; nx++) if (danger(nx,y+1)) {
        return false;
    }
    if (ins) {
        //printf("INSERT %d: %d %d\n", i, x, y);
        ord.insert(tuple<int,int,int>(i,x,y));
    }
    return true;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x, y; scanf("%d %d", &x, &y);
        pos[i] = {x,y};
        s[{x,y}] = i;
    }
    FO(i,0,n) shouldbe(i, pos[i]);
    FO(i,0,n) {
        int id, x, y;
retry:;
        if (i%2 == 0) {
            tie(id, x, y) = *--ord.end();
            ord.erase(--ord.end());
        } else {
            tie(id, x, y) = *ord.begin();
            ord.erase(ord.begin());
        }
        if (!shouldbe(id, {x,y}, false)) {
            goto retry;
        } else {
            res[i] = id;
            s.erase(s.find({x,y}));
            for (int nx = x-1; nx <= x+1; nx++) if (s.count({nx,y+1})) shouldbe(s[{nx,y+1}], {nx,y+1});
            for (int nx = x-1; nx <= x+1; nx++) if (s.count({nx,y-1})) shouldbe(s[{nx,y-1}], {nx,y-1});
        }
    }
    //FO(i,0,n) printf("%d ", res[i]);
    //printf("\n");
    long long pw = 1;
    long long ans = 0;
    long long MOD = 1000000009;
    for (int i = n-1; i >= 0; i--) {
        ans += pw * res[i];
        ans %= MOD;
        pw *= n;
        pw %= MOD;
    }
    printf("%lld\n", ans);
}