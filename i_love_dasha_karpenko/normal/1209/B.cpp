#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1000+7;
const ll INF = 10E17;

ll A[DIM],B[DIM],tt[DIM],state[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        char ch;
        cin>>ch;
        state[i] = ch-'0';
    }
    forn(i,n)cin>>A[i]>>B[i];
    forn(i,n){
        for(ll j = 0;j<DIM;j++){
            if ((j-B[i])%A[i]==0 && j>=B[i]){
                tt[j]+=state[i]^1;
                state[i]^=1;
            }
            else tt[j]+=state[i];
        }
    }
    ll res=  0;
    for(ll j = 0;j<DIM;j++)res = max(res,tt[j]);//cout<<res<<endl;}
    cout<<res<<endl;
    return 0;
}