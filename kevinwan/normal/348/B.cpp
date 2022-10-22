#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e5+10;
ll a[mn],b[mn],tot=1;
vector<int>g[mn];
const ll inf=0x7fffffffffffffff;
inline ll times(ll a,ll b){
    return a<=inf/b?(a*b):inf;
}
inline ll lcm(ll a,ll b){
    return times(a/__gcd(a,b),b);
}
void dfs(int x,int p){
    for(int y:g[x]){
            if(y==p)continue;
        b[y]=times(b[x],(g[x].size()-1));
        dfs(y,x);
        a[x]+=a[y];
    }
    if(g[x].size()==1){
        tot=lcm(tot,b[x]);
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld",a+i);
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    g[1].push_back(0);
    b[1]=1;
    dfs(1,0);
    ll ans=inf;
    if(tot!=inf){
        for(i=1;i<=n;i++){
            if(g[i].size()==1){
                ans=min(ans,a[i]/(tot/b[i]));
            }
        }
        ans*=tot;
    }
    else ans=0;
    printf("%lld",a[1]-ans);
}