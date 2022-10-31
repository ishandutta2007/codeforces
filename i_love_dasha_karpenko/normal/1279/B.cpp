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
const ll DIM = 30000+7;
const ll INF = 10e16;
const ll MOD = 10E8;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,s; cin>>n>>s;
        ll sum = 0,res = 0;
        pp mx = {0,0};
        ll flag = 0;
        forn(i,n){
            ll x; cin>>x;
            if (flag==1)continue;
            sum+=x;
            mx = max(mx,{x,i});
            if (sum>s ){
                flag = 1;
            }

        }
        if (sum<=s)cout<<0<<endl;
        else
        cout<<mx.sc<<endl;
    }
    return 0;

}