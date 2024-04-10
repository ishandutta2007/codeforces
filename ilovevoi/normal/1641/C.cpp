/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  int
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+100;
const ll mod=1e9+7;
const ll base=1e9;

/// you will be the best but now you just are trash
/// goal 3/7


ll st[4*maxn];
ll la[4*maxn];
pll mn[4*maxn];
ll f[4*maxn];
void build(ll id,ll left,ll right)
{
    mn[id]=make_pair(0,left);
    st[id]=0;
    la[id]=0;
    f[id]=0;
    if (left==right)
    {
        return ;
    }
    ll mid=(left+right)/2;
    build(id*2,left,mid);
    build(id*2+1,mid+1,right);
}
pll mer(pll a,pll b)
{
    if (a.ff<=b.ff) return a;
    return b;
}
ll posnw;
void dosth(ll id,ll left,ll right)
{
    if (la[id]==0) return;
    ll mid=(left+right)/2;
    if (st[id*2]!=mid-left+1)
    {
        st[id*2]=mid-left+1;
        f[id*2]=f[id];
    }
    if (st[id*2+1]!=right-mid)
    {
        st[id*2+1]=right-mid;
        f[id*2+1]=f[id];
    }
    mn[id*2]=make_pair(1,left);
    mn[id*2+1]=make_pair(1,mid+1);
    la[id*2]=1;
    la[id*2+1]=1;
    la[id]=0;
}
void update(ll id,ll left,ll right,ll x,ll y)
{
    if (x>right||y<left) return ;
    if (x<=left&&y>=right)
    {
       if (st[id]!=right-left+1) st[id]=right-left+1,f[id]=posnw;
        la[id]=1;
        mn[id]=make_pair(1,left);
        return ;
    }
    dosth(id,left,right);
    ll mid=(left+right)/2;
    update(id*2,left,mid,x,y);
    update(id*2+1,mid+1,right,x,y);
    st[id]=(st[id*2]+st[id*2+1]);
    mn[id]=mer(mn[id*2],mn[id*2+1]);
    f[id]=max(f[id*2],f[id*2+1]);
}
pair<pll,pll> get(ll id,ll left,ll right,ll x,ll y)
{
    if (x>right||y<left) return make_pair(make_pair(0,0),make_pair(base,0));
    if (x<=left&&y>=right) return {{st[id],f[id]},mn[id]};
    dosth(id,left,right);
    ll mid=(left+right)/2;
    auto p=get(id*2,left,mid,x,y);
    auto p1=get(id*2+1,mid+1,right,x,y);
    return make_pair(make_pair(p.ff.ff+p1.ff.ff,max(p.ff.ss,p1.ff.ss)),mer(p.ss,p1.ss));
}
ll t[maxn];
ll l[maxn];
ll r[maxn];
ll x[maxn];
ll id[maxn];
ll pos1[maxn];
vector<ll> adj[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("DELCHAR.inp", "r"))
    {
        freopen("DELCHAR.inp", "r", stdin);
        freopen("DELCHAR.out", "w", stdout);
    }
    ll n, q;
    cin>> n>> q;
    ll cnt=0;
    build(1,1,n);
    for (int i=1;i<=q;i++)
    {
        cin>> t[i];
        if (t[i]==0)
        {
            cin>> l[i]>> r[i]>> x[i];
            if (x[i]==1)
            {
                cnt++;
                id[cnt]=i;
            }
            else
            {
                posnw=i;
                update(1,1,n,l[i],r[i]);
            }
        }
        else
        {
            cin>> x[i];
        }
    }
    for (int t=1;t<=cnt;t++)
    {
        ll idnw=id[t];
        auto p=get(1,1,n,l[idnw],r[idnw]);
        if (p.ff.ff==r[idnw]-l[idnw])
        {
            ll h=max(idnw+1,p.ff.ss+1);
            adj[h].pb(p.ss.ss);
        }
    }
    set<ll> st;
    build(1,1,n);
    for (int i=1;i<=q;i++)
    {
        for (auto to:adj[i])
        {
            st.insert(to);
        }
        if (t[i]==0)
        {
            if (x[i]==0)
            {
                update(1,1,n,l[i],r[i]);
            }
        }
        else
        {
            if (st.count(x[i])) cout <<"YES"<<endl;
            else if (get(1,1,n,x[i],x[i]).ff.ff==1) cout <<"NO"<<endl;
            else cout <<"N/A"<<endl;
        }
    }
}