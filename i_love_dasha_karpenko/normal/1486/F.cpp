#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 3E5+7;
const ll LOG = 24;
const ll INF = 1E18;
ll tin[DIM],tout[DIM],timer = 0,P[DIM][LOG],ptr = DIM+1,only[DIM],cnt[DIM],L[DIM],dp[DIM],L1[DIM];
pair<ll,ll> A[DIM];
vector<ll> G[DIM];
vector<pair<ll,ll> > V[DIM];
void dfs(ll v,ll par){
    tin[v] = ++timer;
    P[v][0] = par;
    for(ll i = 1;i<LOG;++i){
        P[v][i] = P[P[v][i-1]][i-1];
    }
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
    }
    tout[v] = ++timer;
}
ll is_par(ll u,ll v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

ll lca(ll u,ll v){
    if (is_par(u,v))return u;
    if (is_par(v,u))return v;
    for(ll i = LOG-1;i>=0;--i){
        if (!is_par(P[v][i],u))v = P[v][i];
    }
    return P[v][0];
}
ll sub(ll lc,ll v){
    for(ll i = LOG-1;i>=0;--i){
        if (!is_par(P[v][i],lc))v = P[v][i];
    }
    return v;
}
ll res = 0;
ll dfs1(ll v,ll par){
    ll ret = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        ret+=dfs1(to,v);
    }
    ret+=cnt[v];
    res+=ret*only[v];
    return ret;
}
ll dfs2(ll v,ll par){
    for(ll to:G[v]){
        if (to==par)continue;
        dp[v]+=dfs2(to,v);
    }
    dp[v]+=only[v];
    for(auto to:V[v]){
        res+=dp[v];
        if (to.first<DIM)res-=dp[to.first];
        if (to.second<DIM)res-=dp[to.second];
    }

    dp[v]+=cnt[v];
    return dp[v];
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<n;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(2,2);
    ll m;
    cin>>m;

    vector<pair<ll,ll> > ST;
    for(ll i = 1;i<=m;++i){
        ll u,v;
        cin>>u>>v;
        if (u==v){
            only[u]++;
            continue;
        }
        ll lc = lca(u,v);
        if (lc==v)swap(u,v);
        if (lc==u){
            V[lc].push_back({sub(lc,v),++ptr});
            ST.push_back({u,v});
            L1[lc]++;
        }
        else{
            pair<ll,ll> ret = {sub(lc,u),sub(lc,v)};
            if (ret.first>ret.second)swap(ret.first,ret.second);
            V[lc].push_back(ret);
            L[lc]++;
        }
        A[i] = {u,v};

    }

    for(ll i = 1;i<=n;++i){
        map<ll,ll> M;
        map<pair<ll,ll>,ll > S;
        for(auto to:V[i]){
            M[to.first]++;
            M[to.second]++;
            S[to]++;
        }
        for(auto to:V[i]){
            ll in = M[to.first]+M[to.second]-S[to];
            res+=ll(V[i].size())-in;

        }
    }
    res/=2;

    for(ll i = 1;i<=m;++i){
        ll u = A[i].first,v = A[i].second;
        if (u==v)continue;

        ll lc = lca(u,v);

        res+=only[lc];
        cnt[lc]-=2;
        cnt[u]++;
        cnt[v]++;

    }
    dfs1(2,2);
    for(ll i = 1;i<=n;++i){
        res+=only[i]*(only[i]-1)/2;
    }
    memset(only,0,sizeof(only));
    memset(cnt,0,sizeof(cnt));
    for(ll i = 1;i<=m;++i){
        if (A[i].first==A[i].second)continue;
        ll lc = lca(A[i].first,A[i].second);
        ll u = A[i].first,v = A[i].second;
        if (v==lc)swap(u,v);
        if (u==lc){
            only[v]++;
            cnt[sub(u,v)]--;
        }
        else{
            only[v]++;
            only[u]++;
            cnt[sub(lc,u)]--;
            cnt[sub(lc,v)]--;
        }

    }
    dfs2(2,2);
    cout<<res<<endl;

    return 0;
}