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
const ll DIM = 1E5+140;
const ll INF = 1E16;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
vector<ll> G[DIM];
ll flag = 0,vis[DIM],ch[DIM],cnt[DIM],ct[DIM],par[DIM];
void dfs(ll v){
    vis[v] = 1;
    for(ll to:G[v]){
        if (vis[to]==2){
            flag = 1;
            return;
        }
        if (vis[to]==0)
            dfs(to);
    }
    vis[v] = 2;
}
void dfs2(ll v){
    vis[v] =1;
    if (cnt[v]==1 && ch[par[v]]==1)ch[v] = 1;
    for(ll to:G[v]){
        if (vis[to]==0)
            dfs2(to);
    }
}
ll dfs1(ll v){
    ll c = 0;
    par[v] = v;
    for(ll to:G[v]){
        if (vis[to]!=0){
            ++c;
            ++ct[to];
            if (vis[to]<vis[par[v]])par[v] = to;
            continue;
        }
        vis[to] = vis[v]+1;
        c+=dfs1(to);
        if (vis[par[to]]<vis[par[v]])par[v] = par[to];
    }
    c-=ct[v];
    cnt[v] = c;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        forn(i,m){
            ll u,v;
            cin>>u>>v;
            G[u].pb(v);
        }
        ll root = 0;
        forn(xx,60){
            ll v = getInt()%n+1;
            flag = 0;
            memset(vis,0,sizeof(vis));
            dfs(v);
            forn(i,n)
                if (vis[i]==0){
                    flag = 1;
                    break;
                }
            if (flag==0){
                root = v;
                break;
            }
        }
        if (root==0){
            cout<<"-1\n";
        }
        else{
            memset(vis,0,sizeof(vis));
            vis[root] = 1;
            dfs1(root);
            memset(vis,0,sizeof(vis));
            ch[root] = 1;
            dfs2(root);
            vector<ll> ans;
            forn(i,n){
                if (ch[i])
                    ans.pb(i);
            }
            if (ans.size()<(n/5+(n%5!=0)))cout<<"-1";
            else for(ll to:ans)cout<<to<<' ';
            cout<<endl;
        }
        forn(i,n){
            cnt[i] = ct[i] = 0;
            par[i] = 0;
            ch[i] = 0;
            vis[i] = 0;
            G[i].clear();

        }

    }
    return 0;
}