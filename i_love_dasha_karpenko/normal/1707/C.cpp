//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 2e5+7;
int P[N];
vector<int> G[N];
vector<pair<int,int>> be[N];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int tin[N],tout[N],timer = 0,cntbad = 0;
bool bad[N],ans[N];
void euler(int v,int par){
    tin[v] = ++timer;
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        euler(to,v);
    }
    tout[v] = ++timer;
}
bool is_par(int a,int b){
    return tin[a]<=tin[b] && tout[b]<=tout[a];
}
void edgcalc(int v,int par){
    for(auto [to,ind]:be[v]){
        if (!is_par(to,v) && !is_par(v,to)){
            cntbad += 1 - bad[ind];
            bad[ind] = 1;
        }
    }
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        edgcalc(to,v);
    }
}
void dfs(int v,int par){
    vector<pair<int,int> > chg;
    for(auto [to,ind]:be[v]){
        if (bad[ind]){
            cntbad -= 1;
            bad[ind] - 0;
            chg.push_back({ind,1});
        }
    }

    ans[v] = cntbad==0;
    vector<pair<int,int> > E;
    for(auto [to,ind]:be[v]){
        if (is_par(v,to)){
            E.push_back({tin[to],ind});
        }
    }
    sort(E.begin(),E.end());
    int ptr = 0;
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        vector<int> clr;
        while(ptr<E.size() && E[ptr].first<=tout[to]){
            int ind = E[ptr].second;
            cntbad += 1-bad[ind];
            if (!bad[ind]) {
                bad[ind] = 1;
                clr.push_back(ind);
            }
            ptr += 1;
        }

        dfs(to,v);
        for(int ind:clr){
            cntbad -= 1;
            bad[ind] = 0;
        }
    }
    reverse(all(chg));
    for(auto [ind,val]:chg){
        bad[ind] = val;
        cntbad -= 1-val;
        cntbad += val;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i+=1){
        P[i] = i;
    }

    for(int i = 1;i<=m;i+=1){
        int u,v;
        cin>>u>>v;
        if (F(u)!=F(v)){
            P[F(u)] = P[F(v)];
            G[v].push_back(u);
            G[u].push_back(v);
        }
        else{
            be[u].push_back({v,i});
            be[v].push_back({u,i});
        }
    }
    euler(1,1);
    edgcalc(1,1);
    dfs(1,1);
    for(int i = 1;i<=n;i+=1){
        cout<<ans[i];
    }
    cout<<endl;
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}