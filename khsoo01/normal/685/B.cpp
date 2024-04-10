#include<bits/stdc++.h>
using namespace std;
int n,q,par[300005],chi[300005],cen[300005];

vector<int>cg[300005];

void calc (int cur) {
    chi[cur] = 1;
    for(int i=0;i<cg[cur].size();i++) {
        calc(cg[cur][i]);
        chi[cur] += chi[cg[cur][i]];
    }
}

void solve (int cur) {
    int mxv = 0, midx;
    for(int i=0;i<cg[cur].size();i++) {
        solve(cg[cur][i]);
        if(mxv<chi[cg[cur][i]]) {
            mxv = chi[cg[cur][i]];
            midx = cg[cur][i];
        }
    }
    if(mxv*2<=chi[cur]) {
        cen[cur] = cur;
        return;
    }
    cen[cur] = cen[midx];
    while(2*(chi[cur]-chi[cen[cur]])>chi[cur]) cen[cur] = par[cen[cur]];
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++) {
        scanf("%d",&par[i]);
        cg[par[i]].push_back(i);
    }
    calc(1);
    solve(1);
    while(q--) {
        int cur;
        scanf("%d",&cur);
        printf("%d\n",cen[cur]);
    }
}