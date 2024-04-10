#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 50+7;
const ll INF = 1E16;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

char A[DIM][DIM];

ll can,n,m;
void ch(ll i,ll j){
    if (i<1 || i>n || j<1 || j>m)return;
    if(A[i][j]=='G'){
        can = 1;
        return;
    }
    if(A[i][j]=='.')A[i][j] = '#';
}
queue<pp> Q;
ll vis[DIM][DIM];
void Check(ll i,ll j){
    if (i<1 || i>n || j>m || j<1)return;
    if (vis[i][j]==1)return;
    if (A[i][j]=='G' || A[i][j]=='.'){
        vis[i][j] = 1;
        Q.push({i,j});
    }
}
void deikjstra(ll i,ll j){
    if (A[i][j]!='.')return;
    Q.push({i,j});
    vis[i][j] = 1;
    while(!Q.empty()){
        i = Q.front().fi;
        j = Q.front().sc;
        Q.pop();
        Check(i,j-1);
        Check(i,j+1);
        Check(i+1,j);
        Check(i-1,j);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>m;
        forn(i,n){
            forn(j,m){
                cin>>A[i][j];
            }
        }
        can = 0;
        vector<pp> V;
        forn(i,n){
            forn(j,m){
                if (A[i][j]=='B'){
                    ch(i-1,j);
                    ch(i+1,j);
                    ch(i,j-1);
                    ch(i,j+1);
                }
                if (A[i][j]=='G')V.pb({i,j});
            }
        }
        if (can){
            cout<<"No\n";
            continue;
        }
        deikjstra(n,m);
        for(pp to:V)
        if (vis[to.fi][to.sc]==0){
            can = 1;
            break;
        }
        if (can){
            cout<<"No\n";
        }
        else
            cout<<"Yes\n";
        forn(i,n){
            forn(j,m)
                vis[i][j] = 0;
        }
    }

    return 0;
}