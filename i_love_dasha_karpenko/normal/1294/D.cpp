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
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 4*10E4+7;
const ll INF = 10E17;
const ll MAXN = 10E8+7;
ll put[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q,k;
    cin>>q>>k;
    ll last = 0;
    forn(qe,q){
        ll x; cin>>x;
        put[x%k]++;
        while(put[last%k]>0){
            put[last%k]--;
            last++;
        }
        cout<<last<<endl;
    }


    return 0;
}