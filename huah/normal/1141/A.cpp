#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
void dfs(long long x,long long tot)
{
    if(x>m) return;
    if(x==m)
    {
        if(ans==-1) ans=tot;
        else ans=min(ans,tot);
        return;
    }
    dfs(x*2,tot+1);
    dfs(x*3,tot+1);
}
int main()
{
    scanf("%lld%lld",&n,&m);
    dfs(n,0);
    cout<<ans<<endl;
}