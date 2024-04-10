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
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll MAXN = 10E5;
ll n,pr[MAXN+7],vis[MAXN+7];
vector<ll> G[MAXN+7];
vector<pp> edges;
set<ll> S;
ll dist[MAXN+7];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        ll x;
        cin>>x;
        vector<ll> simp;
        for(ll i = 2;i<=sqrt(x);i++){
            ll cnt = 0;
            if (x%i!=0)continue;
            while(x%i==0){
                x/=i;
                cnt++;
            }
            cnt%=2;
            if (cnt==1)simp.pb(i);
        }
        if (x!=1)simp.pb(x);
        else if (simp.size()==0){
            cout<<"1\n";
            return 0;
        }
        while(simp.size()<2)simp.pb(1);
        if (simp[1]!=simp[0] && !(simp[1]>sqrt(MAXN) && simp[0]>sqrt(MAXN))){
            G[simp[0]].pb(edges.size());
            G[simp[1]].pb(edges.size());
            edges.pb({simp[0],simp[1]});

            S.insert(simp[0]);
            S.insert(simp[1]);
        }
    }
    ll res = INF;
    for(ll tt:S){
        //if (tt==1)continue;
        if (tt*tt>MAXN)break;
        queue<ll> q;
        memset(dist,-1,sizeof(dist));
        memset(vis,0,sizeof(vis));
        q.push(tt);
        pr[tt] = tt;
        dist[tt] = 0;
        while(!q.empty()){
            ll v = q.front();
            q.pop();
            for(ll ep:G[v]){
                pp e = edges[ep];
                ll to = e.fi^e.sc^v;
                if (vis[ep]==1)continue;


                if (dist[to]==-1){
                    dist[to] = dist[v]+1;
                    pr[to] = v;
                    vis[ep] = 1;
                    q.push(to);
                }
                else if (pr[to]!=v){
                    res = min(res,dist[to]+dist[v]+1);
                }
            }
        }
    }
    if (res==INF)
        cout<<"-1\n";
    else
        cout<<res<<endl;

    return 0;
}
// a[i]-b[i]>b[j]-a[j]