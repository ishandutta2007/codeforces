#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
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
const ll DIM = 1E3+14;
const ll INF = 1E10;

ll n,m,t,A[DIM][DIM],dist[DIM][DIM];
ll cur;
ll Ch(ll i,ll j){
    if (i<1 || j<1 || i>n || j>m)return 0;
    return A[i][j]==cur;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>t;
    forn(i,n){
        forn(j,m){
            char ch;
            cin>>ch;
            if (ch=='1')A[i][j] = 1;
        }
    }

    queue<pp> Q;
    memset(dist,-1,sizeof(dist));
    forn(i,n){
        forn(j,m){
            cur = A[i][j];
            if (Ch(i+1,j) || Ch(i-1,j) || Ch(i,j-1) || Ch(i,j+1)){
                Q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }
    //cout<<Q.size()<<endl;
    while(!Q.empty()){
        pp v = Q.front();
        Q.pop();
        ll i = v.fi,j = v.sc;
        cur = A[i][j]^1;
        if (Ch(i+1,j) && dist[i+1][j]==-1){
            dist[i+1][j] = dist[i][j]+1;
            Q.push({i+1,j});
        }
        if (Ch(i-1,j) && dist[i-1][j]==-1){
            dist[i-1][j] = dist[i][j]+1;
            Q.push({i-1,j});
        }
        if (Ch(i,j+1) && dist[i][j+1]==-1){
            dist[i][j+1] = dist[i][j]+1;
            Q.push({i,j+1});
        }
        if (Ch(i,j-1) && dist[i][j-1]==-1){
            dist[i][j-1] = dist[i][j]+1;
            Q.push({i,j-1});
        }
    }

    while(t--){
        ll i,j,p;
        cin>>i>>j>>p;
        if (dist[i][j]==-1 || dist[i][j]>p)cout<<A[i][j]<<endl;
        else{
            p-=dist[i][j];
            cout<<(A[i][j]^(p%2))<<endl;
        }
    }
    return 0;
}