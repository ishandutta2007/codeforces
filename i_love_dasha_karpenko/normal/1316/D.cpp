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
const ll DIM = 10E2+7;
const ll INF = 10E16;

ll A[DIM][DIM];
char vis[DIM][DIM];
pp qe[DIM][DIM];
ll n;
queue<pp> Q;
void Check(ll x,ll y,ll dir,pp par){
    if (A[x][y]!=0 || x<1 || x>n || y<1 || y>n || qe[x][y]!=par)return;
    A[x][y] = dir;
    vis[x][y] = 1;
    Q.push({x,y});
}
void dfs(ll x,ll y,ll col = 0){
    //A[x][y] = col;
    if (x>n || x<1 || y>n || y<1 ||  vis[x][y] == 1 )return;
    vis[x][y] = 1;
    A[x][y] = col;
    pp nn = {-1,-1};
    if (qe[x][y+1]==nn){
        //vis[x][y+1]= 1;
        A[x][y] = 4;
        dfs(x,y+1,5);
    }
    if (qe[x][y-1]==nn){
        //vis[x][y-1] = 1;
        A[x][y] = 5;
        dfs(x,y-1,4);
    }
    if (qe[x+1][y]==nn){
       // vis[x+1][y] = 1;
       A[x][y] = 2;
        dfs(x+1,y,3);
    }
    if (qe[x-1][y]==nn){
        //vis[x-1][y] = 1;
        A[x][y] = 3;
        dfs(x-1,y,2);
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

    cin>>n;

    forn(i,n){
        forn(j,n){
            ll x,y;
            cin>>x>>y;
            if (x!=-1){
                A[x][y] = 1;
                vis[x][y] = 1;
            }
            qe[i][j] = {x,y};

        }
    }
    forn(i,n){
        forn(j,n){
            if (A[i][j]!=1)continue;
            Q.push({i,j});
            while(!Q.empty()){
                pp t = Q.front();
                Q.pop();
                Check(t.fi+1,t.sc,3,{i,j});
                Check(t.fi-1,t.sc,2,{i,j});
                Check(t.fi,t.sc+1,5,{i,j});
                Check(t.fi,t.sc-1,4,{i,j});
            }
        }
    }
    forn(i,n){
        forn(j,n){
            if (vis[i][j]!=0 || qe[i][j]!=pp{-1,-1})continue;
            dfs(i,j);
        }
    }
    forn(i,n){
        forn(j,n){
            if (A[i][j]==0){
                cout<<"INVALID\n";
                return 0;
            }
            if (A[i][j]==1 && qe[i][j]!=pp{i,j}){
                cout<<"INVALID\n";
                return 0;
            }
        }
    }
    cout<<"VALID\n";
    forn(i,n){
        forn(j,n){
            if (A[i][j]==1)cout<<'X';
            if (A[i][j]==2)cout<<'D';
            if (A[i][j]==3)cout<<'U';
            if (A[i][j]==4)cout<<'R';
            if (A[i][j]==5)cout<<'L';
        }
        cout<<endl;
    }
    return 0;
}