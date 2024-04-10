#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 200+7;
const ll INF = 1E18;
const ll MAXN = -2*DIM;
ll dist[DIM][DIM];
const ll DIM2 = 2E3+7;
pair<ll,ll> edge[DIM2];
ll B[DIM2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i)
        for(ll j = 1;j<=n;++j)if (i!=j)dist[i][j] = INF;
    for(ll i = 1;i<=m;++i){
        ll u,v,b;
        cin>>u>>v>>b;
        dist[u][v] = 1;
        dist[v][u] = (b?-1:1);
        edge[i] = {u,v};
        B[i] = b;
    }

    for(ll k = 1;k<=n;++k){
        for(ll u = 1;u<=n;++u){
            for(ll v = 1;v<=n;++v){
                if (dist[u][k]==INF || dist[k][v]==INF)continue;
                dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v]);
                if (dist[u][v]<-INF){
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    }

    ll res = 0,mx = 0,add = 0;
    for(ll i = 1;i<=n;++i){
        ll mi = INF,bg = 0;
        for(ll j = 1;j<=n;++j){
            mi = min(mi,dist[i][j]);
            if (dist[i][i]<0){
                cout<<"NO\n";
                return 0;
            }
            bg = max(bg,dist[i][j]);
        }
        if (bg-mi>res){
            res = bg-mi;
            mx = i;
            add = -mi;
        }
    }
    for(ll i = 1;i<=m;++i){
        if (dist[mx][edge[i].first]==dist[mx][edge[i].second]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    cout<<res<<endl;
    for(ll i = 1;i<=n;++i){
        cout<<dist[mx][i]+add<<' ';
    }
    cout<<endl;


    return 0;
}