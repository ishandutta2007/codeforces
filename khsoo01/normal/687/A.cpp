#include<bits/stdc++.h>
using namespace std;
int n,m,stat[100005];
bool vis[100005];

vector<int>cg[100005],ans[2];
vector<pair<int,int> >edg;

void coloring (int idx, int col) {
    if(vis[idx]) return;
    vis[idx] = true;
    stat[idx] = col;
    ans[col].push_back(idx);
    for(int i=0;i<cg[idx].size();i++) {
        coloring(cg[idx][i],1-col);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int A,B;
        scanf("%d%d",&A,&B);
        cg[A].push_back(B);
        cg[B].push_back(A);
        edg.push_back({A,B});
    }
    for(int i=1;i<=n;i++) {
        coloring(i,0);
    }
    for(int i=0;i<m;i++) {
        if(stat[edg[i].first]+stat[edg[i].second]!=1) {
            puts("-1"); return 0;
        }
    }
    for(int i=0;i<2;i++) {
        printf("%d\n",ans[i].size());
        for(int j=0;j<ans[i].size();j++) {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
}