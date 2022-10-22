#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll p=6578436587LL;
const int mn=1e6+10;
vector<int> g[mn];
ll h[mn];
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
            int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
    for(i=1;i<=n;i++){
        for(int x:g[i]){
            h[i]=h[i]*p+x;
        }
    }
    sort(h+1,h+1+n);
    int ln=1;
    ll ans=0;
    for(i=1;i<=n;i++){
        if(h[i]==h[ln])ans+=i-ln;
        else ln=i;
    }
    for(i=1;i<=n;i++)g[i].push_back(i);
    for(i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
    memset(h,0,sizeof(h));
    for(i=1;i<=n;i++){
        for(int x:g[i]){
            h[i]=h[i]*p+x;
        }
    }
    sort(h+1,h+1+n);
    ln=1;
    for(i=1;i<=n;i++){
        if(h[i]==h[ln])ans+=i-ln;
        else ln=i;
    }
    printf("%lld",ans);
}