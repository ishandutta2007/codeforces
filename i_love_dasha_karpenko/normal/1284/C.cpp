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
const ll DIM = 250000 +7;
const ll INF = 10E10;
ll MOD;
ll fact[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    cin>>MOD;
    fact[0] = 1;
    ll res = 0;
    forn(i,n){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    res=(res+(fact[n]*n)%MOD)%MOD;
    for(ll i = 2;i<=n;i++)res = (((((n-i+1)*fact[i])%MOD*(n-i+1))%MOD*fact[n-i])%MOD+res)%MOD;
    cout<<res<<endl;
    return 0;
}