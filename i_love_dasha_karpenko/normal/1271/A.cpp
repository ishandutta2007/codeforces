#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 10E5+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ll res = 0;
    if (e>f){
        ll g = min(a,d);
        res+=g*e;
        a-=g;
        d-=g;
        g = min(min(b,c),d);
        res+=g*f;
    }
    else{
        ll g = min(min(b,c),d);
        res+=f*g;
        b-=g;
        c-=g;
        d-=g;
        g = min(a,d);
        res+=g*e;
    }
    cout<<res<<endl;

    return 0;

}