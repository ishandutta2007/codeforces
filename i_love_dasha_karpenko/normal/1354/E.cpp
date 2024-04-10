#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
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
const int DIM = 5000+14;
const ll INF = 1E17;

ll col[DIM],cnt[3][DIM],cmp[DIM],cho[DIM];
pp P[DIM][DIM];
vector<ll> G[DIM];
ll comp = 0;
void dfs(ll v,ll c){
    col[v] = c;
    ++cnt[c][comp];
    cmp[v] = comp;
    for(ll to:G[v]){
        if (col[to]!=0 && abs(col[v]-col[to])!=1){
            cout<<"NO\n";
            exit(0);
        }
        if (col[to]!=0 )continue;
        dfs(to,3-c);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll n1,n2,n3;
    cin>>n1>>n2>>n3;
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    forn(i,n){
        if (cmp[i]!=0)continue;
        ++comp;
        dfs(i,1);
    }
    P[0][0] = {0,1};
    forn(i,comp){
        for(ll w = 0;w<=n2;++w){
            if (P[i-1][w].sc==0)continue;
            if (n2>=w+cnt[1][i]){
                P[i][w+cnt[1][i]] = {w,1};
            }
            if (n2>=w+cnt[2][i]){
                P[i][w+cnt[2][i]] = {w,2};
            }
        }
    }
    ll w = n2,pos = comp;
    if (P[pos][w].sc==0){
        cout<<"NO\n";
        return 0;
    }
    while(pos>0){
        cho[pos] = P[pos][w].sc;
        w = P[pos][w].fi;
        --pos;
    }
    ll cnt = 0;
    cout<<"YES\n";
    forn(i,n){
        if (cho[cmp[i]]==2)col[i] = 3-col[i];
        if (col[i]==1)cout<<"2";
        else{
            if (cnt<n1){
                ++cnt;
                cout<<"1";
            }
            else cout<<"3";
        }
    }
    cout<<endl;
    return 0;
}