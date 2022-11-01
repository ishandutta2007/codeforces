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
        int n,p;cin>>p;
        n=1<<p;
        vector<vector<int>>e(n<<1);
        for(int i=1;i<n;++i)
        {
            int u,v;cin>>u>>v;
            e[u].push_back(i+n);
            e[i+n].push_back(u);
            e[v].push_back(i+n);
            e[i+n].push_back(v);
        }
        vector<int>a(n<<1),b(n<<1);
        int cur=1;
        a[1]=1<<p;
        b[1]=1<<p;
        function<void(int,int)>dfs=[&](int u,int fa)
        {
            if(u!=1)
            {
                if(b[fa]==(1<<p))
                    a[u]=(1<<p)|(cur++);
                else if(b[fa]==0)
                    a[u]=cur++;
                else a[u]=a[fa]^(1<<p);
                b[u]=b[fa]^a[u];
            }
            for(int v:e[u])
                if(v!=fa) dfs(v,u);
        };
        dfs(1,0);
        cout<<1<<'\n';
        for(int i=1;i<=n;++i) cout<<a[i]<<(i==n?'\n':' ');
        for(int i=n+1;i<=n+n-1;++i) cout<<a[i]<<(i==n+n-1?'\n':' ');
        int mx=0;
        for(int i=1;i<=n+n-1;++i) mx=max(mx,b[i]);
        assert(mx==(1<<p));
    }
}
/*
val  xorsum
1000 1000
1xxx 0xxx
0xxx 0000
0yyy 0yyy
1yyy 1000
*/