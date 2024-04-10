//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll LOG = 21;
struct graph{

    vector<ll> tin,tout,sub;
    vector<vector<ll> > P,G;
    ll sz,timer = 0;
    void add_edge(ll u,ll v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void resize(ll n){
        sz = n;
        tin.resize(n+7);
        tout.resize(n+7);
        P.resize(n+7);
        sub.resize(n+7);
        G.resize(n+7);
        for(ll i = 1;i<=n;++i){
            P[i].resize(LOG+3);
        }

    }
    void calc(ll v,ll par){
        tin[v] = ++timer;
        P[v][0] = par;
        sub[v] = 1;
        for(ll i = 1;i<=LOG;++i){
            P[v][i] = P[P[v][i-1]][i-1];
        }
        for(ll to:G[v]){
            if (to==par)
                continue;
            calc(to,v);
            sub[v]+=sub[to];
        }
        tout[v] = ++timer;
    }
    ll is_par(ll a,ll b){
        return tin[a]<=tin[b] && tout[b]<=tout[a];
    }
    ll lca(ll a,ll b){
        if (is_par(a,b))
            return a;
        if (is_par(b,a))
            return b;
        for(ll i = LOG;i>=0;--i){
            if (!is_par(P[a][i],b))
                a = P[a][i];
        }
        return P[a][0];
    }

};

ll ans[DIM];
ll a[2],s[2];
void recalc(ll c,graph &D){
    s[c] = 1;
    for(ll to:D.G[a[c]]){
        if (D.is_par(to,a[c^1])){
            continue;
        }
        if (to==D.P[a[c]][0])
            continue;
        s[c]+=D.sub[to];
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        graph D;
        ll n;
        cin>>n;
        D.resize(n);
        for(ll i = 1;i<n;++i){
            ll u,v;
            cin>>u>>v;
            ++u;
            ++v;
            D.add_edge(u,v);
        }
        D.calc(1,1);
        ans[0] = n*(n-1)/2;

        for(ll to:D.G[1]){
            ans[1]+=D.sub[to]*(n-D.sub[to]-1);
        }
        ans[1]/=2;
        ans[1]+=n-1;
        a[0] = 1,a[1] = 2;
        s[0] = s[1] = 0;
        recalc(0,D);
        recalc(1,D);
        ans[2] = s[0]*s[1];

        for(ll i = 3;i<=n;++i){
            ll lc = D.lca(a[0],a[1]);
            if (lc!=1)
                n/=0;
            if (a[0]==lc){
                if (D.is_par(a[1],i)){
                    a[1] = i;
                    recalc(1,D);
                }
                else if (!D.is_par(i,a[1])){
                    if (D.lca(i,a[1])!=1)
                        break;
                    a[0] = i;
                    recalc(0,D);
                }
            }
            else {
                if (D.is_par(a[0],i)){
                    a[0] = i;
                    recalc(0,D);
                }
                else if (D.is_par(a[1],i)){
                    a[1] = i;
                    recalc(1,D);
                }
                else if (!D.is_par(i,a[1]) && !D.is_par(i,a[0]))
                    break;
            }

            ans[i] = s[0]*s[1];
        }
        ll sum = 0;
        for(ll i = n;i>=0;--i){
            ans[i]-=sum;
            sum+=ans[i];
        }
        for(ll i = 0;i<=n;++i){
            cout<<ans[i]<<' ';
            ans[i] = 0;
        }

        cout<<endl;
    }
    return 0;
}