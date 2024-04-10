/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for(ll i=a;i<=b;i++)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e3+5;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 0/7

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
    ll n, a, b;
    cin>> a>> b>>n;
    ll cnt=0;
    while (n)
    {
        ll t=__gcd(n,(cnt%2==0?a:b));
        n-=t;
        cnt++;
    }
    //cout <<cnt<<endl;
    if (cnt%2==0)
    {
        cout <<1<<endl;
    }
    else
    {
        cout <<0<<endl;
    }
}