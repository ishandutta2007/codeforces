#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=0x3f3f3f3f;
const int mn=1e6+10;
ll gcd(ll a,ll b){
    while(b)a%=b,swap(a,b);
    return a;
}
vector<int>g[mn];
ll a[mn];
int o[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",a+i);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[b].push_back(a);
        }
        for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
        iota(o,o+n+1,0);
        sort(o+1,o+n+1,[](int a,int b){return g[a]<g[b];});
        ll cum=0,ans=0;
        for(int i=1;i<=n;i++){
            if(g[o[i]]!=g[o[i-1]]){
                if(g[o[i-1]].size())ans=gcd(ans,cum);
                cum=0;
            }
            cum+=a[o[i]];
        }
        if(g[o[n]].size())ans=gcd(ans,cum);
        printf("%lld\n",ans);
        for(int i=0;i<=n;i++)g[i].clear(),a[i]=o[i]=0;
    }
}