#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100000  +7;
const ll INF = 10E10;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll a,b,c,r; cin>>a>>b>>c>>r;
        if (a>b)swap(a,b);
        ll right = c+r,left = c-r;
        right = max(right,a);
        left = min(left,b);
        ll res = 0;
        res+=max(0ll,left-a);
        res+=max(0ll,b-right);
        cout<<res<<endl;
    }
    return 0;
}