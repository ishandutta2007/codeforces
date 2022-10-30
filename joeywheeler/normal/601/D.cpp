#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
ll MOD[2] = {1000000009ll, 1000000007ll};
ll BASE[2] = {137ll,137ll};
struct hsh {

    ll val[2];
    int len;

    hsh() {
        val[0] = val[1] = len = 0;
    }
    hsh(char c) {
        val[0] = val[1] = c;
        len = 1;
    }
    bool operator<(const hsh &o) const {
        FO(i,0,2) if (val[i] != o.val[i]) return val[i] < o.val[i];
        return len < o.len;
    }
};

ll pw[2][300005];

hsh mrge(hsh a, hsh b) {
    FO(i,0,2) a.val[i] = (a.val[i]*pw[i][b.len]+b.val[i])%MOD[i];
    a.len += b.len;
    return a;
}

int n;
vector<int> u[300005];
char ch[300005];
int c[300005];
hsh h[300005];
int ts[300005];

set<hsh> s;

void go(int i, int p) {
    h[i] = mrge(h[p], ch[i]);
    ts[i] = 1;
    for (int j : u[i]) if (j != p) {
        go(j, i);
        ts[i] += ts[j];
    }
}

void go3(int i, int p) {
    s.insert(h[i]);
    for (int j : u[i]) if (j != p) go3(j, i);
}

void go2(int i, int p) {
    //printf("p[%d]=%d\n", i, p);
    int mxc = -1;
    for (int j : u[i]) if (j != p) {
        if (mxc == -1 || ts[mxc] < ts[j]) mxc = j;
    }
    for (int j : u[i]) if (j != p && j != mxc) {
        go2(j, i);
        s.clear();
    }
    if (mxc != -1) {
        go2(mxc, i);
    }
    for (int j : u[i]) if (j != p && j != mxc) {
        go3(j, i);
    }
    s.insert(h[i]);
    //printf("%d: mxc=%d, sz(s)=%d\n", i, mxc, sz(s));
    c[i] += sz(s);
}

int main() {
    FO(j,0,2) {
        pw[j][0] = 1;
        FO(i,1,300005) pw[j][i] = (pw[j][i-1]*BASE[j])%MOD[j];
    }
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", c+i+1);
    scanf("%s", ch+1);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    go2(1,0);
    int mx = -1;
    FO(i,1,n+1) mx = max(mx, c[i]);
    printf("%d\n", mx);
    int l = 0;
    FO(i,1,n+1) {
        if (c[i] == mx) l++;
        //printf("%d ", c[i]);
    }
    //printf("\n");
    printf("%d\n", l);
}