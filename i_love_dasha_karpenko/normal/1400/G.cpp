#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 300000+7;
const ll INF = 1E19;
const ll MAXN = 50;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
const ll MOD = 998244353;
pp A[DIM];
ll vis[DIM];
vector<ll> G[DIM];
vector<pp> V[DIM];
ll ptr = 0;
void dfs(ll v,ll par){
    vis[v] = ptr;
    for(ll to:G[v]){
        if (vis[to]!=0)continue;
        dfs(to,v);
    }
}

set<ll> S[MAXN];
const ll masksz = po(22)+7;

ll cnt[MAXN][MAXN];
ll can[MAXN][MAXN];
ll res[2][MAXN];

void recalc(){
    memset(cnt,0,sizeof(cnt));

    forn(pos,ptr){
        vector<ll> vv;
        for(ll to:S[pos])vv.pb(to);
        ll msz = po(S[pos].size());
         memset(can,0,sizeof(can));
        for(ll i = 0;i<vv.size();++i){
            for(ll j = 0;j<vv.size();++j){
                ll a = vv[i];
                ll b = vv[j];
                for(ll to:G[a]){
                    if (to==b){
                        can[i+1][j+1] = 1;
                        break;
                    }
                }
            }
        }

        cnt[pos][0] = 1;
        for(ll mask = 1;mask<msz;++mask){

            vector<ll> v1;
            forn(i,vv.size()){
                if (po(i-1)&mask){
                    v1.pb(i);
                }
            }
            ll flag = 0;
            for(ll i:v1){
                for(ll j:v1){
                    if (can[i][j]){
                        flag =  1;
                        break;
                    }
                }
                if (flag)break;
            }
            if (flag)continue;

            cnt[pos][v1.size()]++;
        }
    }
    memset(res,0,sizeof(res));
    res[1][0] = 1;
    forn(i,ptr){
        for(ll w = 0;w<MAXN;++w){
            for(ll w1 = 0;w1<=w;++w1){
                res[0][w]=(res[0][w]+res[1][w-w1]*cnt[i][w1])%MOD;
            }
        }
        for(ll w = 0;w<MAXN;++w){
            res[1][w] = res[0][w];
            res[0][w] = 0;
        }
    }

}
ll fact[DIM],rev[DIM];
ll binpow(ll x,ll power){
    x%=MOD;
    ll mult = x;
    x = 1;
    while(power){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
ll re(ll x){
    return binpow(x,MOD-2);
}
ll C(ll n,ll k){
    if (n<k)return 0;
    if (k<0)return 0;
    return (((fact[n]*rev[k])%MOD)*rev[n-k])%MOD;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    forn(i,DIM-1)fact[i] = (fact[i-1]*i)%MOD;
    rev[0] = re(1);
    forn(i,DIM-1)rev[i] = re(fact[i]);
    ll n,m;
    cin>>n>>m;
    forn(i,n){
        ll l,r;
        cin>>l>>r;
        V[l].pb({i,0});
        V[r+1].pb({i,1});
    }
    memset(vis,-1,sizeof(vis));
    forn(i,m){
        ll u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
        vis[v] = 0;
        vis[u] = 0;
    }
    forn(i,n){
        if (vis[i]==0){
            ++ptr;
            dfs(i,i);
        }
    }

    ll cnt = 0,ans = 0;
    recalc();
    res[1][0] = 1;
    forn(i,n){
        ll flag = 0;
        for(pp to:V[i]){
            if (vis[to.fi]!=-1){
                if (to.sc==0)S[vis[to.fi]].insert(to.fi);
                else S[vis[to.fi]].erase(to.fi);
                flag = 1;
            }
            else{
                if (to.sc==0)
                    ++cnt;
                else
                    --cnt;
            }
        }
        if (flag){
            recalc();
        }
        for(ll ct = 0;ct<MAXN;++ct){
            ll base = res[1][ct];
            ll need = i-ct;
            ans=(ans+base*C(cnt,need))%MOD;
        }


    }
    cout<<ans<<endl;


    return 0;
}