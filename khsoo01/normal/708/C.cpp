#include<bits/stdc++.h>
using namespace std;
int n, missing[400005], sz[400005], par[400005];
pair<int,int> dt[400005][2];

vector<int> cg[400005];

void getpar (int cur, int prev) {
    par[cur] = prev;
    sz[cur] = 1;
    for(int i=0;i<cg[cur].size();i++) {
        if(cg[cur][i] == prev) continue;
        getpar(cg[cur][i], cur);
        sz[cur] += sz[cg[cur][i]];
    }
}

void update (int cur, int prev, int val) {
    pair<int,int> tmp = {val, prev};
    if(dt[cur][0] < tmp) {
        dt[cur][1] = dt[cur][0];
        dt[cur][0] = tmp;
    }
    else if(dt[cur][1] < tmp) {
        dt[cur][1] = tmp;
    }
}

int solve (int cur, int prev) {
    if(missing[cur] == -1) {
        for(int i=0;i<cg[cur].size();i++) {
            if(cg[cur][i] == prev) continue;
            int csz = (par[cur] == cg[cur][i] ? n - sz[cur] : sz[cg[cur][i]]);
            update(cur, cg[cur][i], max(solve(cg[cur][i], cur),(csz<=n/2?csz:0)));
        }
        missing[cur] = prev;
    }
    else if(missing[cur] && missing[cur] != prev) {
        int csz = (par[cur] == missing[cur] ? n - sz[cur] : sz[missing[cur]]);
        update(cur, missing[cur], max(solve(missing[cur], cur),(csz<=n/2?csz:0)));
        missing[cur] = 0;
    }
    if(dt[cur][0].second == prev) return dt[cur][1].first;
    else return dt[cur][0].first;
}

int main()
{
    scanf("%d",&n);
    memset(missing, -1, sizeof(missing));
    for(int i=1;i<n;i++) {
        int A, B;
        scanf("%d%d",&A,&B);
        cg[A].push_back(B);
        cg[B].push_back(A);
    }
    getpar(1, 0);
    for(int i=1;i<=n;i++) {
        int flag = 1;
        for(int j=0;j<cg[i].size();j++) {
            int csz = (sz[i] < sz[cg[i][j]] ? n - sz[i] : sz[cg[i][j]]);
            if(csz > n/2) {
                if(csz - solve(cg[i][j], i) > n/2) flag = 0;
            }
        }
        printf("%d ",flag);
    }
}