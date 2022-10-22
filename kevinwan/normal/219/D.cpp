#include <bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
vector<int> g[mn],d[mn];
int dif[mn];
int ans;
void dfs(int x,int p){
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        int c=d[x][i];
        ans+=c;
        dif[y]=dif[x]+1-2*c;
        dfs(y,x);
    }
}
int main()
{
    int n,i,a,b;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        d[a].push_back(0);
        d[b].push_back(1);
    }
    dfs(1,0);
    int bes=0x3f3f3f3f;
    vector<int> v;
    for(i=1;i<=n;i++){
        if(ans+dif[i]<bes)v.clear(),bes=ans+dif[i],v.push_back(i);
        else if(ans+dif[i]==bes)v.push_back(i);
    }
    printf("%d\n",bes);
    for(int x:v)printf("%d ",x);
}