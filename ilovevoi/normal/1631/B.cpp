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
        ll n;
        cin>> n;
        for (int i=1;i<=n;i++)
        {
           cin>> a[i];
        }
        ll cnt=0;
        for (int i=n;i>=1;i--)
        {
            if (a[i]==a[n]) continue;
            ll cl=min((ll)i,(n-i));
            cnt++;
            for (int j=i;j>=i-cl+1;j--) a[j]=a[n];
            i=i-cl+1;
        }
        cout <<cnt<<endl;
    }
}