#include <bits/stdc++.h>
using namespace std;
const int mn=3e5+10;
vector<int>g[mn];
vector<int>ic[mn];
set<int>s;
int ans[mn];
void dfs(int x,int p){
    for(int y:ic[x])if(ans[y]!=-1)s.erase(ans[y]);
    for(int y:ic[x])if(ans[y]==-1)ans[y]=*s.begin(),s.erase(ans[y]);
    for(int y:ic[x])s.insert(ans[y]);
    for(int y:g[x])if(y!=p)dfs(y,x);
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            ic[i].push_back(x);
        }
    }
    for(i=1;i<=m;i++)s.insert(i);
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(ans,-1,sizeof(ans));
    dfs(1,0);
    int kkk=1;
    for(i=1;i<=m;i++)kkk=max(kkk,ans[i]);
    for(i=1;i<=m;i++)if(ans[i]==-1)ans[i]=1;
    printf("%d\n",kkk);
    for(i=1;i<=m;i++)printf("%d ",ans[i]);
}