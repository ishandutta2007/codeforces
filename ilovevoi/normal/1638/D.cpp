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

const ll maxn=1e3+30;
const ll mod=998244353;
const ll base=3e18 ;

/// you will be the best but now you just are trash
/// goal 3/7

vector<pair<pll,ll>> vt;
ll a[maxn][maxn];
bool dd[maxn][maxn];
ll pos;
ll n, m;
bool kt(ll x,ll y)
{
    if (x>=1&&x+1<=n&&y>=1&&y+1<=m)
    {
        if (dd[x][y]) return false;
        set<ll> st;
        if (a[x][y]!=0) st.insert(a[x][y]);
        if (a[x+1][y]!=0) st.insert(a[x+1][y]);
        if (a[x][y+1]!=0) st.insert(a[x][y+1]);
        if (a[x+1][y+1]!=0) st.insert(a[x+1][y+1]);
        if (st.size()==1)
        {
            pos=(*st.begin());
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}
void dfs(ll x,ll y)
{
    dd[x][y]=1;
    /*if (!kt(x,y))
    {
        cout <<x<<" "<<y<<" wtf"<<endl;
        for (auto p:vt)
        {
            cout <<p.ff.ff<<" "<<p.ff.ss<<" "<<p.ss<<endl;
        }
        exit(0);
    }*/
    a[x][y]=0;
    a[x+1][y]=0;
    a[x][y+1]=0;
    a[x+1][y+1]=0;
    vt.pb(make_pair(make_pair(x,y),pos));
    for (int t=-1;t<=1;t++)
    {
        for (int t1=-1;t1<=1;t1++)
        {
            ll x1=x+t;
            ll y1=y+t1;
            if (kt(x1,y1))
            {
                dfs(x1,y1);
            }
        }
    }
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
    cin>> n>> m;
    F(i,1,n)
    {
        F(j,1,m)
        {
            cin>> a[i][j];
        }
    }
    F(i,1,n)
    {
        F(j,1,m)
        {
            if (kt(i,j))
            {
                dfs(i,j);
            }
        }
    }
     F(i,1,n)
    {
        F(j,1,m)
        {
           if (a[i][j])
           {
               cout <<-1;
               return 0;
           }
        }
    }
    reverse(vt.begin(),vt.end());
    cout <<vt.size()<<endl;
    for (auto p:vt)
    {
        cout <<p.ff.ff<<" "<<p.ff.ss<<" "<<p.ss<<endl;
    }
}