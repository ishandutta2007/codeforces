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
const ll DIM = 10E4+7;
const ll INF = 10e16;
const ll MOD = 10E8;
ll pos[DIM],fen[DIM],n,m;
void add(ll pos){
    for(ll i = pos;i<=n;i+=(i&-i))fen[i]++;
}
ll sum(ll pos){
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i))ret+=fen[i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        cin>>n>>m;

        forn(i,n){
            ll x; cin>>x;
            pos[x]  =i;
            fen[i] = 0;
        }
        ll depth = 0;
        ll res = 0;
        forn(i,m){
            ll x; cin>>x;
            if (depth>=pos[x]){
                res++;
                add(pos[x]);
            }
            else{
                res+=2*(pos[x]-1-sum(pos[x]))+1;
                add(pos[x]);
                depth = pos[x];
            }
        }
        cout<<res<<endl;
    }
    return 0;

}