//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'a')
const int N = 3e5+7;
const int base = 27;
int G[N<<1][base];
int sz[N];
void calcsz(int v){
    sz[v] = 1;
    for(int c = 0;c<base;++c)
        if (G[v][c]!=-1){
            calcsz(G[v][c]);
            sz[v]+=sz[G[v][c]];
        }
}
int dsum[N],rsum[N];
int cnt = 0,ptr = 0,n;
vector<pair<int,int> > del;
void trav(int v,int root){
    for(int c = 0;c<base;++c){
        if (G[v][c]==-1)
            continue;
        if (G[root][c]==-1){
            G[root][c] = G[v][c];
            del.push_back({root,c});
            cnt+=sz[G[v][c]];
            continue;
        }
        trav(G[v][c],G[root][c]);
    }
}
void dfs(int v,int depth = 0){
    ++rsum[depth];
    int big = 0,cl = 0;
    for(int c = 0;c<base;++c){
        if (G[v][c]==-1)
            continue;
        int to = G[v][c];
        dfs(to,depth+1);
        if (sz[to]>sz[big])
            big = to,cl = c;
    }
    if (big!=0){
        cnt = sz[big];
        ptr = n;
        for(int c = 0;c<base;++c){
            if (G[v][c]==-1 || c==cl)
                continue;
            trav(G[v][c],big);
        }
        dsum[depth]+=sz[v]-cnt;
        for(auto [v,c]:del){
            G[v][c] = -1;
        }
        del.clear();

    }
}
void solve(){
    memset(G,-1,sizeof(G));
    cin>>n;
    for(int i = 1;i<n;++i){
        int a,b;
        char ch;
        cin>>a>>b>>ch;
        G[a][gi(ch)] = b;
    }
    calcsz(1);

    dfs(1);
    pair<int,int> res = {n,n};
    for(int d = 0;d<=n;++d) {

        res = min(res, {n-dsum[d], d});
    }

    cout<<res.first<<'\n'<<res.second+1<<endl;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();

    return 0;
}