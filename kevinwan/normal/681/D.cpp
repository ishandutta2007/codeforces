#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
vector<int> g[mn];
int a[mn],v[mn];
bool idk[mn],suc=1;
vector<int>ans;
void dfs(int x){
    if(a[x]!=v[x])suc=0;
    for(int y:g[x]){
        if(!v[y])v[y]=v[x];
        dfs(y);
    }
    if(v[x]==x)ans.push_back(x);
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        idk[b]=1;
    }
    for(i=1;i<=n;i++)scanf("%d",a+i),v[a[i]]=a[i];
    for(i=1;i<=n;i++)if(!idk[i])dfs(i);
    if(!suc)printf("-1");
    else{
        printf("%d\n",ans.size());
        for(int x:ans)printf("%d\n",x);
    }
}