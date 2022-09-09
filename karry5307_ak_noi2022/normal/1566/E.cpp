#include<cstdio>
#include<vector>
using namespace std;
int n,t,F[200005],ans;
vector<int> vec[200005];
void dfs(int x,int fa)
{
    if(vec[x].size()==1 && x!=1) 
    {
        ans++;
//        printf("F[%d]=%d\n",x,0);
        return;
    }
    bool flag=false;
    for(auto &p : vec[x])
    {
        if(p==fa) continue;
        dfs(p,x);
        if(F[p]==1) ans--;
        else flag=true;
    }
    if(flag) F[x]=1;
    if(!flag) ans++;
//    printf("F[%d]=%d\n",x,F[x]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            vec[i].clear();
            F[i]=0;
        }
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        dfs(1,0);
        printf("%d\n",ans);
    }
}