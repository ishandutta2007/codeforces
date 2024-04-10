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

const ll maxn=3e5+100;
const ll mod=1e9+7;
const ll base=5e18;

/// you will be the best but now you just are trash
/// goal 3/7

ll n, q;
ll x[maxn];
ll w[maxn];
vector<ll> adj[maxn];
vector<pll> adj1[maxn];
ll st[4*maxn];
void update(ll id,ll left,ll right,ll x,ll diff)
{
    if (x>right||x<left) return ;
    if (left==right)
    {
        st[id]=min(st[id],diff);
        return ;
    }
    ll mid=(left+right)/2;
    update(id*2,left,mid,x,diff);
    update(id*2+1,mid+1,right,x,diff);
    st[id]=min(st[id*2],st[id*2+1]);
}
ll get(ll id,ll left,ll right,ll x,ll y)
{
    if (x>right||y<left) return base;
    if (x<=left&&y>=right) return st[id];
    ll mid=(left+right)/2;
    return min(get(id*2,left,mid,x,y),get(id*2+1,mid+1,right,x,y));
}
ll res[maxn];
void dosth()
{
    for (int t=0;t<4*maxn;t++) st[t]=base;
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
    ll n, q;
    cin>> n>> q;
    for (int i=1;i<=n;i++)
    {
        cin>> x[i]>> w[i];
    }
    stack<ll> st;
    F(i,1,n)
    {
        while (!st.empty()&&w[i]<w[st.top()]) st.pop();
        if (st.size())
        {
            adj[i].pb(st.top());
           // cout <<i<<" "<<st.top()<<" chk1"<<endl;
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--)
    {
         while (!st.empty()&&w[i]<w[st.top()]) st.pop();
        if (st.size())
        {
            adj[st.top()].pb(i);
        }
        st.push(i);
    }
    for (int i=1;i<=q;i++)
    {
        ll l, r;
        cin>> l>> r;
        adj1[r].pb(make_pair(l,i));
    }
    dosth();
    for (int i=1;i<=n;i++)
    {
        for (auto to:adj[i])
        {
           /* if (i==3&&to==2)
            {
                cout <<x[i]-x[to]<<" "<<w[i]+w[to]<<" wtf"<<endl;
            }*/
           // cout <<(x[i]-x[to])*(w[i]+w[to])<<" wtf"<<endl;
            update(1,1,n,to,(x[i]-x[to])*(w[i]+w[to]));
        }
        for (auto to:adj1[i])
        {
            ll l=to.ff;
            ll id=to.ss;
            res[id]=get(1,1,n,l,n);
        }
    }
    for (int i=1;i<=q;i++) cout <<res[i]<<endl;
}