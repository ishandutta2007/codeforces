#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct box {
    int in, out, w, s, v;
};

int dpc[1005][1005];
int n, S;
box b[505];

//box nb[505];
//int nbs;
int tdp[1005];

int atpos[1005][1005], atposs[1005];

#define INF 1e9
int dp(int cp, int cs) {
    if (cs < 0) return -INF;
    if (dpc[cp][cs] != -1) return dpc[cp][cs];

    //nbs = 0;
    FO(i,0,n) {
        if (i != cp && b[cp].in <= b[i].in && b[i].out <= b[cp].out) {
            //nb[nbs++] = b[i];
            int x = i;
            dp(x, min(cs-b[x].w,b[x].s));
        }
    }

    for (int i = b[cp].out; i >= b[cp].in; i--) {
        atposs[i]=0;
    }

    FO(i,0,n) {
        if (i != cp && b[cp].in <= b[i].in && b[i].out <= b[cp].out) {
            atpos[b[i].in][atposs[b[i].in]++] = i;
        }
    }

    for (int i = b[cp].out; i >= b[cp].in; i--) {
        if (i == b[cp].out) tdp[i] = 0;
        else {
            tdp[i] = tdp[i+1];
            // place something here?
            FO(j,0,atposs[i]) {
                int x = atpos[i][j];
                // place x?
                tdp[i] = max(tdp[i], dp(x, min(cs-b[x].w,b[x].s)) + tdp[b[x].out] + b[x].v);
            }
        }
    }

    return dpc[cp][cs] = tdp[b[cp].in];
}

int main() {
    scanf("%d %d", &n, &S);
    FO(i,0,n) {
        scanf("%d %d %d %d %d", &b[i].in, &b[i].out, &b[i].w, &b[i].s, &b[i].v);
    }
    b[n].in = 0;
    b[n].out = 1001;
    b[n].w = 0;
    b[n].s = S;
    b[n].v = 0;
    n++;
    memset(dpc,-1,sizeof dpc);
    printf("%d\n", dp(n-1,S));
}