#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
int v[mn],a[mn],o[mn];
void dfs(int x){
    if(!v[x^1])v[x^1]=3-v[x],dfs(x^1);
    if(!v[o[x]])v[o[x]]=3-v[x],dfs(o[x]);
}
int main()
{
    int n,i,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a[i]=x-1;
        o[x-1]=y-1;
        o[y-1]=x-1;
    }
    for(i=0;i<2*n;i++)if(!v[i])v[i]=1,dfs(i);
    for(i=0;i<n;i++){
        printf("%d %d\n",v[a[i]],3-v[a[i]]);
    }
}