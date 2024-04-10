#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 200007;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
ll n,m,vis[DIM],timer =  0,tin[DIM],tmin[DIM],V[DIM],start,va[DIM],vb[DIM],a,b;
vector<pp> G[DIM];
set<ll> dots;
void dfs(ll v,ll par){
    vis[v] = 1;
    tin[v] = tmin[v] = ++timer;
    ll flag = 0;
    ll cnt = 0;
    for(pp r:G[v]){
        if (V[r.sc]==1)continue;
        ll to = r.fi;
        if (vis[to]==1){
            tmin[v] = min(tmin[v],tin[to]);
        }
        else{
            cnt++;
            V[r.sc] = 1;
            dfs(to,v);
            tmin[v] = min(tmin[v],tmin[to]);
        if (tmin[to]>=tin[v] && v!=start){
            dots.insert(v);
        }
        }

        //if (tmin[to]==tin[v])cnt++;
    }
    if (v==start && cnt>1)dots.insert(v);
}
void dfsa(ll v){
    va[v] = 1;
    for(pp r:G[v]){
        ll to = r.fi;
        if (to==b)continue;
        if (va[to]==0){
            va[to] = 1;
            dfsa(to);
        }
    }
}
void dfsb(ll v){
    vb[v] = 1;
    for(pp r:G[v]){
        ll to = r.fi;
        if (to==a)continue;
        if (vb[to]==0){
            vb[to] = 1;
            dfsb(to);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        cin>>n>>m>>a>>b;
        dots.clear();
        forn(i,n){
            tin[i] = tmin[i] = vis[i] = va[i] = vb[i] = 0;
            G[i].clear();
        }
        forn(i,m){
            V[i] = 0;
        }
        forn(i,m){
            ll x,y; cin>>x>>y;
            G[x].pb({y,i});
            G[y].pb({x,i});
        }
        forn(i,n){
            if (vis[i]==0){
                start = i;
                timer = 0;
                dfs(i,-1);
            }
        }
        if (dots.count(a)==0 || dots.count(b)==0){
            cout<<0<<endl;
            continue;
        }
        dfsa(a);
        dfsb(b);
        ll cnt1 = 0,cnt2 = 0;
        forn(i,n){
            if (i==a || i==b)continue;
            if (va[i]+vb[i]!=2){
                if (va[i]==1)cnt1++;
                else cnt2++;
            }
        }
        cout<<cnt1*cnt2<<endl;
    }

    return 0;
}