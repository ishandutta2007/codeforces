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

const ll maxn=5e5+10;
const ll mod=1e9+7;
const ll base=1e18;

/// you will be the best but now you just are trash
/// goal 3/7


struct tk
{
    ll la=0;
    ll val=0;
    ll valmn=0;
    ll mn=0;
};
tk st[4*maxn];
ll k;
vector<ll> vt;
ll x[maxn];
ll y[maxn];
tk mer(tk a,tk b)
{
    tk c;
    c.val=(a.val+b.val);
    c.mn=min(a.mn,b.mn);
    if (c.mn==a.mn)
        c.valmn+=a.valmn;
    if (c.mn==b.mn)
        c.valmn+=b.valmn;
    return c;
}
void dosth(ll id,ll left,ll right)
{
    st[id*2].mn+=st[id].la;
    st[id*2+1].mn+=st[id].la;
    st[id*2].la+=st[id].la;
    st[id*2+1].la+=st[id].la;
    st[id].la=0;
}
void update(ll id,ll left,ll right,ll x,ll y,ll val)
{
    if (x>right||y<left)
        return ;
    if (x<=left&&y>=right)
    {
        st[id].la+=val;
        st[id].mn+=val;
        return ;
    }
    dosth(id,left,right);
    ll mid=(left+right)/2;
    update(id*2,left,mid,x,y,val);
    update(id*2+1,mid+1,right,x,y,val);
    st[id]=mer(st[id*2],st[id*2+1]);
}
void build(ll id,ll left,ll right)
{
    if (left==right)
    {
        st[id].la=0;
        st[id].val=vt[left]-vt[left-1];
        st[id].valmn=vt[left]-vt[left-1];
        st[id].mn=0;
        return ;
    }
    ll mid=(left+right)/2;
    build(id*2,left,mid);
    build(id*2+1,mid+1,right);
    st[id]=mer(st[id*2],st[id*2+1]);
}
ll n;
string s;
ll get1()
{
    ll ans=n;
    if (st[1].mn==0)
    {
        ans-=st[1].valmn;
    }
    return ans;
}
ll get()
{
    vt.clear();
    vt.pb(1);
    vt.pb(n+1);
    vector<pair<pll,pll>> vt1;
    bool chk=false;
    bool chk1=false;
    ll x=1;
    ll y=1;
    ll x1=1;
    ll y1=1;
    for (auto to:s)
    {
        if (to=='R') y1++;
        else x1++;
    }
    x1=n-x1+1;
    y1=n-y1+1;
    for (auto to:s)
    {
        if (to=='R')
        {
            y++;
            chk1=true;
        }
        else
        {
            x++;
            chk=true;
        }
        ll lx=x;
        ll rx=x;
        ll ly=y;
        ll ry=y;
        if (chk)
        {
            rx=lx+x1-1;
        }
        if (chk1)
        {
            ry=ly+y1-1;
        }
        //cout <<lx<<" "<<rx<<" "<<ly<<" "<<ry<<endl;
        vt1.pb(make_pair(make_pair(lx,1),make_pair(ly,ry)));
        vt1.pb(make_pair(make_pair(rx+1,-1),make_pair(ly,ry)));
        vt.pb(ly);
        vt.pb(ry+1);
     //   cout <<lx<<" "<<rx<<" "<<ly<<" "<<ry<<endl;
    }
    sort(vt.begin(),vt.end());
    vt.resize(unique(vt.begin(),vt.end())-vt.begin());
    ll len=vt.size()-1;
    build(1,1,len);
    ll ans=0;
    sort(vt1.begin(),vt1.end());
    for (int i=0;i<vt1.size();i++)
    {
        if (i)
        {
            ll kc=(vt1[i].ff.ff-vt1[i-1].ff.ff);
          //  cout <<vt1[i].ff.ff<<" "<<vt1[i-1].ff.ff<<" "<<get1()<<" chk1"<<endl;
            ans=(ans+kc*get1());
        }
        ll diff=vt1[i].ff.ss;
        ll l=vt1[i].ss.ff;
        ll r=vt1[i].ss.ss;
     //   cout <<vt1[i].ff.ff<<" "<<l<<" "<<r<<" "<<diff<<endl;
        l=lower_bound(vt.begin(),vt.end(),l)-vt.begin()+1;
        r=lower_bound(vt.begin(),vt.end(),r+1)-vt.begin();
        update(1,1,len,l,r,diff);
    }
    return ans+1;
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
    ll t;
    cin>> t;
    while (t--)
    {
        cin>> n;
        cin>> s;
        cout <<get()<<endl;
    }
}