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

const ll maxn=2e5+100;
const ll mod=1000003 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7
ll a[maxn];
ll f[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll t;
    cin>> t;
    while(t--)
    {
        ll n, k;
        cin>> n>> k;
        for (int i=1; i<=n; i++)
        {
            cin>> a[i];
            f[a[i]]++;
        }
        for (int i=1; i<=n; i++)
            f[i]+=f[i-1];
        ll l=1;
        pair<ll,pll> res=make_pair(base,make_pair(base,base));
        for (ll i=1; i<=n; i++)
        {
            if ((f[i])-(n-(f[i]))<k)
                continue;
            while (l<i&&(f[i]-f[l])-(n-(f[i]-f[l]))>=k)
                l++;
            res=min(res,make_pair(i-l,make_pair(l,i)));
        }
        cout <<res.ss.ff<<" "<<res.ss.ss<<endl;
        ll st=1;
        for (int i=1; i<=k-1; i++)
        {
            ll cntnw=0;
            ll p=st-1;
            while (cntnw<=0)
            {
                ll h=-1;
                p++;
                if (a[p]>=res.ss.ff&&a[p]<=res.ss.ss)
                    h=1;
                cntnw+=h;
            }
            cout <<st<<" "<<p<<endl;
            st=p+1;
        }
        cout <<st<<" "<<n<<endl;
        for (int i=1;i<=n;i++) f[i]=0;
    }
}