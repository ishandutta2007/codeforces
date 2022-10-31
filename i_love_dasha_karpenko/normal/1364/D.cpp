#include <bits/stdc++.h>

using namespace std;
typedef int  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
//typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll DIM2 = 1E6+7;
const ll INF = 1E9;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll n,m,k;
vector<ll> G[DIM];
ll depth[DIM],P[DIM];

ll start = 0,finish = 0;
ll dfs(ll v,ll par){
    for(ll i = 0;i<ll(G[v].size());++i){
        ll to = G[v][i];
        if (to==par)continue;
        if (depth[to]!=-1 && depth[to]<depth[v]){
            if (depth[v]-depth[to]+1<=k){
                cout<<2<<endl;
                cout<<depth[v]-depth[to]+1<<endl;
                cout<<v<<' ';
                return to;
            }
            else{
                start = v;
                finish = to;
            }
            continue;
        }
        if (depth[to]!=-1)continue;
        depth[to] = depth[v]+1;
        P[to] = v;
        ll ret = dfs(to,v);
        if (ret!=0){
            cout<<v<<' ';
        }
        if (ret==v){
            cout<<endl;
            exit(0);
        }
        else return ret;
    }
    return 0;
}
ll cl[DIM];

void solve(ll v,ll par,ll col){
    cl[v] = col;
    for(ll i = 0;i<ll(G[v].size());++i){
        ll to = G[v][i];
        if (to==par)continue;
        if (cl[to]!=-1)continue;
        solve(to,v,col^1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;

    forn(i,m){
        ll u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    memset(depth,-1,sizeof(depth));
    depth[1] = 0;
    dfs(1,1);

    if (start!=0){
        cout<<1<<endl;
        ll ct = k/2+k%2;
        while(ct>0 && start!=P[finish] && start!=finish){
            cout<<start<<' ';
            start = P[start];
            start = P[start];
            ct--;
        }
        return 0;
    }



    memset(cl,-1,sizeof(cl));
    solve(1,1,0);
    cout<<1<<endl;
    ll mid = k/2+k%2;
    ll ct = 0;
    forn(i,n)if (cl[i])ct++;
    if (ct>=mid){
        forn(i,n){
            if (cl[i]){cout<<i<<' ';
            mid--;
            }
            if (mid==0)break;
        }
    }
    else{
        forn(i,n){
            if (!cl[i]){cout<<i<<' ';
            mid--;
            }
            if (mid==0)break;
        }
    }
    cout<<endl;

    return 0;
}