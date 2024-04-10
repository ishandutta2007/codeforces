#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll b[mn],g[mn];
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%lld",b+i);
    for(i=0;i<m;i++)scanf("%lld",g+i);
    sort(b,b+n);
    sort(g,g+m);
    ll ans=0;
    if(g[0]<b[n-1]){
        printf("-1");
        return 0;
    }
    for(i=1;i<m;i++)ans+=g[i];
    ans+=b[n-1];
    bool nou=0;
    if(b[n-1]==g[0])nou=1;
    for(i=n-2;i>=0;i--){
        if(i==n-2&&!nou){
            ans+=g[0];
            ans+=(m-1)*(b[i]);
        }
        else ans+=b[i]*m;
    }
    printf("%lld",ans);
}