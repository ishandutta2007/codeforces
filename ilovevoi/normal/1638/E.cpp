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
const ll base=3e18 ;

/// you will be the best but now you just are trash
/// goal 3/7

ll n, q;
ll a[maxn];
ll val[maxn];
set<pair<pll,ll>> st;
ll st1[4*maxn];
ll la[4*maxn];
void dosth(ll id,ll left,ll right)
{
    if (left==right) return ;
    st1[id*2]+=la[id];
    st1[id*2+1]+=la[id];
    la[id*2]+=la[id];
    la[id*2+1]+=la[id];
    la[id]=0;
}
void update(ll id,ll left,ll right,ll x,ll y,ll diff)
{
   if (x>right||y<left) return ;
   if (x<=left&&y>=right)
   {
       st1[id]+=diff;
       la[id]+=diff;
       return ;
   }
   ll mid=(left+right)/2;
   dosth(id,left,right);
   update(id*2,left,mid,x,y,diff);
   update(id*2+1,mid+1,right,x,y,diff);
}
ll get(ll id,ll left,ll right,ll x)
{
    if (x>right||x<left) return 0;
    if (left==right) return st1[id];
    dosth(id,left,right);
    ll mid=(left+right)/2;
    return get(id*2,left,mid,x)+get(id*2+1,mid+1,right,x);
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
    cin>> n>> q;
    st.insert(make_pair(make_pair(1,n),1));
    for (int t=1;t<=q;t++)
    {
        string s;
        cin>> s;
        if (s=="Color")
        {
            ll l, r, c;
            cin>>l>> r>> c;
            auto it=st.lower_bound(make_pair(make_pair(l,base),base));
            it--;
            vector<pair<pll,ll>> vt;
            while (it!=st.end()&&(*it).ff.ff<=r)
            {
                vt.pb((*it));
                auto p=(*it).ff;
                ll colnw=(*it).ss;
                update(1,1,n,p.ff,p.ss,val[colnw]);
                it++;
            }
            for (auto to:vt) st.erase(to);
           /* if (t==1)
            {
                cout <<vt.size()<<endl;
                cout <<vt[0].ff.ff
            }*/
            if (1)
            {
                if (vt[0].ff.ff<l)
                {
                    st.insert(make_pair(make_pair(vt[0].ff.ff,l-1),vt[0].ss));
                    update(1,1,n,vt[0].ff.ff,l-1,-val[vt[0].ss]);
                }
                if (vt.back().ff.ss>r)
                {
                    st.insert(make_pair(make_pair(r+1,vt.back().ff.ss),vt.back().ss));
                    update(1,1,n,r+1,vt.back().ff.ss,-val[vt.back().ss]);
                }
            }
            update(1,1,n,l,r,-val[c]);
            st.insert(make_pair(make_pair(l,r),c));
        }
        else if (s=="Add")
        {
            ll c, x;
            cin>>c>> x;
            val[c]+=x;
        }
        else
        {
            ll x;
            cin>> x;
            auto it=st.lower_bound(make_pair(make_pair(x,base),base));
            it--;

            cout <<get(1,1,n,x)+val[(*it).ss]<<endl;
        }
    }
}