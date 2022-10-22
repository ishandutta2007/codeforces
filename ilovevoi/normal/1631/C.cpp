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
        ll n, k;
        cin>> n>> k;
        if (n==4&&k==3)
        {
            cout <<-1<<endl;
            continue;
        }
        if (k==n-1)
        {
            for (int j=3; j<n-3; j++)
            {
                if (j>n-1-j)
                    break;
                cout <<j<<" "<<n-1-j<<endl;
            }
            cout <<n-2<<" "<<n-1<<endl;
            cout <<n-3<<" "<<1<<endl;
            cout <<2<<" "<<0<<endl;
        }
        else
        {
            for (int j=0;j<n-1;j++)
            {
                if (j>n-1-j) break;
                if (j==k||j==0||j==n-1-k) continue;
                cout <<j<<" "<<n-1-j<<endl;
            }
            cout <<n-1<<" "<<k<<endl;
            ll t=n-1-k;
            if (k!=0) cout <<t<<" "<<0<<endl;
        }
    }
}