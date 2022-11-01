#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
// const int mod=1e9+7;
// #define inf 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3fll
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const double eps=1e-8;
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<ll>a(n+1),sum(n+1);
        for(int i=1;i<=n;++i) cin>>a[i],sum[i]=sum[i-1]+a[i];
        vector<vector<ll>>mn(n+1,vector<ll>(20)),mx(n+1,vector<ll>(20));
        for(int i=0;i<=n;++i) mn[i][0]=mx[i][0]=sum[i];
        for(int i=1;1<<i<=n+1;++i)
            for(int j=0;j+(1<<i)-1<=n;++j)
            {
                mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
                mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
            }
        auto qmn=[&](int l,int r)
        {
            int k=__lg(r-l+1);
            return min(mn[l][k],mn[r-(1<<k)+1][k]);
        };
        auto qmx=[&](int l,int r)
        {
            int k=__lg(r-l+1);
            return max(mx[l][k],mx[r-(1<<k)+1][k]);
        };
        vector<int>l(n+1),r(n+1);
        stack<int>s;
        for(int i=1;i<=n;++i)
        {
            while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
            if(s.empty()) l[i]=0;
            else l[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n;i>=1;--i)
        {
            while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
            if(s.empty()) r[i]=n+1;
            else r[i]=s.top();
            s.push(i);
        }
        bool flag=true;
        for(int i=1;i<=n;++i)
            if(qmx(i,r[i]-1)-qmn(l[i],i-1)>a[i]) flag=false;
        cout<<(flag?"YES\n":"NO\n");
    }
}