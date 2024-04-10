#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define INF 10000

vector<int> u[5005];
int f[5005][5005][2];
int ei[5005][5005];
int p[5005];
int nlt[5005];
int nln[5005];
int n;

int dp(int i, int nl1, int r);

int dp2(int i, int j, int nl1, int r) {
    if (j < 0) return nl1 == 0 ? 0 : INF;
    if (u[i][j] == p[i]) return dp2(i,j-1,nl1,r);
    int edi = ei[i][u[i][j]];
    if (f[edi][nl1][r] != -1) return f[edi][nl1][r];
    int up = nlt[edi];
    int lo = nl1-nln[u[i][j]];
    int &res = f[edi][nl1][r];
    res = INF;
    FO(f,max(lo,0),min(nl1+1,up+1)) {
        FO(k,0,2) {
            res = min(res, dp2(i,j-1,f,r) + dp(u[i][j],nl1-f,k) + (k != r));
        }
    }
    return res;
}

int dp(int i, int nl1, int r) {
    if (sz(u[i]) == 1) {
        return nl1 == r ? 0 : INF;
    } else {
        return dp2(i,sz(u[i])-1,nl1,r);
    }
}

int go(int i, int j) {
    p[i] = j;
    int cur = 0;
    for(int x : u[i]) if (x != j) {
        nlt[ei[i][x]] = cur;
        cur += go(x,i);
    }
    if (cur == 0) cur = 1;
    nln[i] = cur;
    return cur;
}

int main() {
    scanf("%d", &n);
    if (n == 2) {
        printf("1\n");
        return 0;
    }
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        ei[x][y] = i;
        ei[y][x] = i;
        u[y].push_back(x);
        u[x].push_back(y);
    }
    memset(f,-1,sizeof f);
    int nl = 0;
    FO(i,1,n+1) if (sz(u[i]) == 1) {
        nl++;
    }
    FO(i,1,n+1) if (sz(u[i]) > 1) {
        go(i,0);
        printf("%d\n", min(dp(i,nl/2,0), dp(i,nl/2,1)));
        return 0;
    }
}