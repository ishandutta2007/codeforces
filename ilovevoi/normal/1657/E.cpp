#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=264;
const ll base=3e18;
const ll mod=998244353 ;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// you are fucking stupid
/// goal 1/8

ll dp[maxn][maxn];
ll n, k;
ll gt[maxn];
ll gtv[maxn];
ll mu(ll a,ll n)
{
    if (n==0)
        return 1;
    if (n==1)
        return a;
    ll t=mu(a,n/2);
    if (n%2==0)
        return (t*t)%mod;
    return ((t*t)%mod*a)%mod;
}
void setup()
{
    gt[0]=1;
    for (int i=1; i<maxn; i++)
    {
        gt[i]=(gt[i-1]*i)%mod;
    }
    gtv[maxn-1]=mu(gt[maxn-1],mod-2);
    for (int i=maxn-2; i>=0; i--)
    {
        gtv[i]=(gtv[i+1]*(i+1))%mod;
    }
}
ll nck(ll n,ll k)
{
    if (n<k)
        return 0;
    return ((gt[n]*gtv[k])%mod*gtv[n-k])%mod;
}
ll f(ll id,ll p)
{
    if (id==0&&p==0) return 1;
    if (p==0) return 0;
    if (dp[id][p]!=-1) return dp[id][p];
    ll ans=0;
    for (int t=0;t<=id;t++)
    {
        ll sl= nck(id,t);
        ll cnt=(id-t)*t+((t*(t-1)/2));
        ll slc=mu(k-p+1,cnt);
        ans=(ans+(((f(id-t,p-1)*sl)%mod)*slc)%mod)%mod;
    }
   // cout <<id<<" "<<p<<" "<<ans<<" chk1"<<endl;
    return dp[id][p]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp","r"))
    {
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    setup();
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>> n>> k;
    cout <<f(n-1,k)<<endl;
}