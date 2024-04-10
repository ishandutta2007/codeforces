#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef int  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E4+7;
const ll INF = 1E9;
const ll GT = 1E3+7;
ll A[DIM],dist[DIM][GT];
bool en[DIM][GT];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,m){
        cin>>A[i];
    }
    ll g,r;
    cin>>g>>r;
    sort(A+1,A+1+m);
    memset(dist,-1,sizeof(dist));
    ll dd = A[1];
    dist[1][0] = 0;
    deque<pp> Q;
    Q.push_front({1,0});

    while(!Q.empty()){
        pp t = Q.front();

        Q.pop_front();
        ll v = t.fi;
        if (en[t.fi][t.sc]==1)continue;
        if (v+1<=m){
            ll left =  (abs(A[v+1]-A[v])+t.sc)%g;
            if (left==(abs(A[v+1]-A[v])+t.sc) ||(abs(A[v+1]-A[v])+t.sc)==g){

                ll di = dist[t.fi][t.sc];
                if ((abs(A[v+1]-A[v])+t.sc)==g)di+=g+r;
                ll dir = 1;
                if (dist[v+1][left]==-1 || dist[v+1][left]>di){
                    dist[v+1][left] = di;
                    if (di==dist[t.fi][t.sc])
                    Q.push_front({v+1,left});
                    else{
                        Q.pb({v+1,left});
                    }
                }
            }
        }
        if (v-1>0){
            ll left =  (abs(A[v-1]-A[v])+t.sc)%g;
            if (left==(abs(A[v-1]-A[v])+t.sc) || (abs(A[v-1]-A[v])+t.sc)==g){
                ll di = dist[t.fi][t.sc];
                if ((abs(A[v-1]-A[v])+t.sc)==g)di+=g+r;
                if (dist[v-1][left]==-1 || dist[v-1][left]>di){
                    dist[v-1][left] = di;
                    if (dist[t.fi][t.sc]==di)
                    Q.push_front({v-1,left});
                    else Q.pb({v-1,left});
                }
            }
        }
        en[t.fi][t.sc] = 1;

    }
    ll res = INF;
    forn(i,m-1){
        if (A[m]-A[i]>g || dist[i][0]==-1)continue;
        res = min(res,dist[i][0]+A[m]-A[i]);
    }
    if (res==INF)res = -1;
    cout<<res<<endl;
    return 0;
}