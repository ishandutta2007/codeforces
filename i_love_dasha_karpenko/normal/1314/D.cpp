#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
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
const ll DIM = 80+7;
const ll INF = 10E10;

ll n,col[DIM],A[DIM][DIM],dist[DIM][20];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll k;
    cin>>n>>k;
    forn(i,n)
        forn(j,n)
            cin>>A[i][j];
    ll res = INF;
    forn(mmm,20000){
        forn(i,n)col[i] = rnd()%2;
        forn(i,n){
            if (col[i]==col[1])dist[i][0] = INF;
            else {
                dist[i][0] = A[1][i];
            }
        }
        forn(turn,k-1){
            forn(i,n){
                dist[i][turn] = INF;
                forn(j,n){
                    if (col[i]==col[j])continue;
                    if (dist[j][turn-1]>=INF)continue;
                    dist[i][turn] = min(dist[i][turn],dist[j][turn-1]+A[j][i]);
                }
            }
        }
        res = min(res,dist[1][k-1]);
    }
    cout<<res<<endl;
    return 0;
}