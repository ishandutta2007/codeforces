#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int mod=998244353;
const int mod=1e9+7;
#define inf 0x3f3f3f3f
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1),b(n+1),c(n+1);
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) cin>>b[i];
        for(int i=1;i<=n;++i) cin>>c[i];
        vector<int>f(n+1);
        iota(f.begin(),f.end(),0);
        function<int(int)>getf=[&](int x){return f[x]==x?x:f[x]=getf(f[x]);};
        for(int i=1;i<=n;++i) f[getf(a[i])]=getf(b[i]);
        vector<bool>vis(n+1);
        for(int i=1;i<=n;++i)
            if(c[i]) vis[getf(c[i])]=true;
        int ans=1,z=0;
        for(int i=1;i<=n;++i)
            if(f[i]==i&&!vis[i]) ++z;
        for(int i=1;i<=n;++i) if(a[i]==b[i]&&!c[i]) --z;
        while(z--) ans=(ans<<1)%mod;
        cout<<ans<<'\n';
    }
}