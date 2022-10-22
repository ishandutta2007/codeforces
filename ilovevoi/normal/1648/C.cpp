/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e6+30;
const ll mod=998244353;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 3/7

ll a[maxn];
ll cnt[maxn];
ll gt[maxn];
ll f[maxn];
ll st[4*maxn];
ll la[4*maxn];

ll mu(ll a,ll n)
{
    if (n==0)
        return 1;
    ll t=mu(a,n/2);
    if (n%2==0)
        return (t*t)%mod;
    else
        return ((t*t)%mod*a)%mod;
}
void dosth(ll id,ll left,ll right)
{
    st[id*2]=(st[id*2]*la[id])%mod;
    st[id*2+1]=(st[id*2+1]*la[id])%mod;
    la[id*2]=(la[id*2]*la[id])%mod;
    la[id*2+1]=(la[id*2+1]*la[id])%mod;
    la[id]=1;
}
void update(ll id,ll left,ll right,ll x,ll diff)
{
    if (x>right||x<left)
        return ;
    if (left==right)
    {
        st[id]=diff;
        return ;
    }
    dosth(id,left,right);
    ll mid=(left+right)/2;
    update(id*2,left,mid,x,diff);
    update(id*2+1,mid+1,right,x,diff);
    st[id]=(st[id*2]+st[id*2+1])%mod;
}
void update1(ll id,ll left,ll right,ll x,ll y,ll diff)
{
    if (x>right||y<left)
        return ;
    if (x<=left&&y>=right)
    {
        st[id]=(st[id]*diff)%mod;
        la[id]=(la[id]*diff)%mod;
        return ;
    }
    dosth(id,left,right);
    ll mid=(left+right)/2;
    update1(id*2,left,mid,x,y,diff);
    update1(id*2+1,mid+1,right,x,y,diff);
    st[id]=(st[id*2]+st[id*2+1])%mod;
}
ll get(ll id,ll left,ll right,ll x,ll y)
{
    if (x>right||y<left)
        return 0;
    if (x<=left&&y>=right)
        return st[id];
    dosth(id,left,right);
    ll mid=(left+right)/2;
    return (get(id*2,left,mid,x,y)+get(id*2+1,mid+1,right,x,y))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    for (int t=0; t<4*maxn; t++)
        la[t]=1;
    ll n, m;
    cin>> n>> m;
    F(i,1,n)
    {
        ll x;
        cin>> x;
        cnt[x]++;
    }
    gt[0]=1;
    F(i,1,maxn-1)
    {
        gt[i]=(gt[i-1]*i)%mod;
    }
    for (int i=1; i<=m; i++)
    {
        cin>> a[i];
    }
    ll p=gt[n-1];
    ll len=maxn-1;
    for (int i=1; i<maxn; i++)
    {
        if (cnt[i])
        {
            p=(p*mu(gt[cnt[i]],mod-2))%mod;
        }
    }
    //cout <<p<<endl;
   for (int i=1; i<maxn; i++)
    {
        if (cnt[i])
        {
         //   cout <<i<<" "<<(p*cnt[i])<<" chk1"<<endl;
            update(1,1,len,i,(p*cnt[i])%mod);
        }
    }
    ll ans=0;
    ll lennw=n-1;
    for (int i=1; i<=m; i++)
    {
        if (i>=2)
        {
            if (cnt[a[i-1]]==0)
            {
                break;
            }
            ll h=a[i-1];
            ll val=(cnt[h]*mu(lennw,mod-2))%mod;

        //    cout <<h<<" "<<cnt[h]<<" wtf"<<endl;
            update1(1,1,len,1,h-1,val);
            update1(1,1,len,h+1,len,val);
           update1(1,1,len,h,h,((cnt[h]-1)*mu(lennw,mod-2))%mod);
          cnt[h]--;
        lennw--;
        }
        if (i==n+1)
        {
            ans=(ans+1)%mod;
            break;
        }
        ans=(ans+get(1,1,len,1,a[i]-1))%mod;
      //  cout <<ans<<" "<<i<<" wtf"<<endl;
    }
    cout <<ans<<endl;
}