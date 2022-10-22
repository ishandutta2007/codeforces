#include <bits/stdc++.h>

using namespace std;
const int mn=1e5+10;
vector<int> g[mn];
int d[mn];
double ans=0;
void dfs(int x,int p){
    ans+=1./(d[x]+1);
    for(int y:g[x]){
            if(y==p)continue;
        d[y]=d[x]+1;
        dfs(y,x);
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    printf("%.20f",ans);
}