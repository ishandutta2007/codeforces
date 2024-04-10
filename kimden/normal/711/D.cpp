#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int MAXN = 200002;
const ll mod = 1000000007;

int n;
vector<int> g[MAXN];
bool c[MAXN];
bool c1[MAXN];

void dfs2(int v,int p){
    c1[v] = true;
    int u;
    bool parent_visited = false;
    for(int i=0;i<g[v].size();i++){
        u = g[v][i];
        if(u==p){
            continue;
        }
        if(c1[u]){
            continue;
        }
        dfs2(u,v);
    }
}

pii dfs(int v,int p){
    c[v] = true;
    int u;
    bool parent_visited = false;
    for(int i=0;i<g[v].size();i++){
        u = g[v][i];
        if(u==p){
            if(!parent_visited){
                parent_visited = true;
                continue;
            }
        }
        if(c[u]){
            return make_pair(1,u);
        }
        pii res = dfs(u,v);
        if(res.first>0){
            if(v==res.second){
                return make_pair(-res.first-1,res.second);
            }else{
                return make_pair(res.first+1,res.second);
            }
        }else if(res.first<0){
            return res;
        }
    }
    return make_pair(0,-1);
}

ll binpow(ll y,ll x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return y%mod;
    }
    ll ans = binpow((y%mod),x>>1LL)%mod;
    ll ans2 = ans;
    ans *= ans2;
    ans %=mod;
    if(x%2){
        ans *= (y%mod);
        ans %= mod;
    }
    ans %= mod;
    return ans;
}

int main()
{
    cin >> n;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        a--;
        g[i].push_back(a);
        g[a].push_back(i);
        c[i] = false;
        c1[i] = false;
    }
    ll ans = 1;
    ll rest = n;
    pii pr;
    for(int i=0;i<n;i++){
        if(!c1[i]){
            pr = dfs(i,-1);
            dfs2(i,-1);
            ans *= (binpow(2,-pr.first)+mod-2);
            ans %= mod;
            rest += pr.first;
        }
    }
    ans *= binpow(2,rest);
    ans %= mod;
    cout << ans;
    return 0;
}