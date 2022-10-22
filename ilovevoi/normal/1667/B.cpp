#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=7e5+100;
const ll base=3e18;
const ll mod= 1e9+7 ;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// have medal in APIO
/// goal 2/8

ll a[maxn];

struct stmx
{
    ll st[4*maxn];
    void dosth(ll n)
    {
        for (int i=0; i<=4*n; i++)
        {
            st[i]=-base;
        }
    }
    ll  get(ll id,ll left,ll right,ll x,ll y)
    {
        if (left>y||right<x)
            return -base;
        if (x<=left&&right<=y)
        {
            return st[id];
        }
        ll mid =(left+right)/2;
        return max(get(id*2,left,mid,x,y),get(id*2+1,mid+1,right,x,y));

    }
    void update(ll id,ll left,ll right, ll pos,ll diff)
    {
        if (pos<left||pos>right)
            return ;
        if (left==right)
        {
            st[id]=max(st[id],diff);
            return;
        }
        ll mid =(left+right)/2;
        update(id*2,left,mid,pos,diff);
        update(id*2+1,mid+1,right,pos,diff);
        st[id]=max(st[id*2],st[id*2+1]);
    }
} man,man1;
ll dp[maxn];

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
    ll t;
    cin>> t;
    while (t--)
    {
        ll n;
        cin>> n;
        ll nw=0;
        vector<ll> vt;
        vt.pb(0);
        for (int i=1; i<=n; i++)
        {
            ll x;
            cin>> x;
            a[i]=a[i-1]+x;
            vt.pb(a[i]);
        }
        sort(vt.begin(),vt.end());
        vt.resize(unique(vt.begin(),vt.end())-vt.begin());
        ll len=vt.size();
        dp[0]=0;
        map<ll,ll> mp;
        man.dosth(len+3);
        man1.dosth(len+3);
        for (int i=1; i<=n; i++)
        {
            ll h=lower_bound(vt.begin(),vt.end(),a[i-1])-vt.begin()+1;
            if (mp.count(a[i-1]))
            {
                mp[a[i-1]]=max(mp[a[i-1]],dp[i-1]);
            }
            else
            {
                mp[a[i-1]]=dp[i-1];
            }
            man.update(1,1,len,h,dp[i-1]-(i-1));
            man1.update(1,1,len,h,dp[i-1]+(i-1));
            h=lower_bound(vt.begin(),vt.end(),a[i])-vt.begin()+1;
            dp[i]=-base;
            if (mp.count(a[i]))
            {
                dp[i]=mp[a[i]];
            }
            dp[i]=max(dp[i],max(man.get(1,1,len,1,h-1)+i,man1.get(1,1,len,h+1,len)-i));
        }
        cout <<dp[n]<<endl;
    }
}