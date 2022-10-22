#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int cnt;
const int MAXLOG = 18;

int depth[100005];
int par[100005][MAXLOG];
int in[100005];
int out[100005];
vector <int> graf[100005];
bool visited[100005];

void dfs(int v, int lv){
    in[v] = ++cnt;
    visited[v] = 1;
    depth[v] = lv;
    for(int i=1; i<MAXLOG; i++){
        par[v][i] = par[par[v][i-1]][i-1];
    }
    for(auto c : graf[v]){
        dfs(c, lv+1);
    }
    out[v] = ++cnt;
}

bool isp(int a, int b){
    return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b){
    if(isp(a, b)) return a;
    if(isp(b, a)) return b;
    for(int i=MAXLOG-1; i>=0; i--){
        if(par[a][i] == 0) continue;
        if(!isp(par[a][i], b)) a = par[a][i];
    }
    return par[a][0];
}

int stlca[100005][MAXLOG];
int stmin[100005][MAXLOG];
int stmax[100005][MAXLOG];
int lg[100005];

int minquery(int l, int r){
    int x = lg[r-l+1];
    if(in[stmin[l][x]] < in[stmin[r+1-(1<<x)][x]]) return stmin[l][x];
    else return stmin[r+1-(1<<x)][x];
}

int maxquery(int l, int r){
    int x = lg[r-l+1];
    if(in[stmax[l][x]] > in[stmax[r+1-(1<<x)][x]]) return stmax[l][x];
    else return stmax[r+1-(1<<x)][x];
}

int lcaquery(int l, int r){
    int x = lg[r-l+1];
    return lca(stlca[l][x], stlca[r+1-(1<<x)][x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int q;
    cin >> q;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        par[i][0] = x;
        graf[x].push_back(i);
    }
    dfs(1, 0);
    for(int i=1; i<=n; i++) stlca[i][0] = i;
    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            stlca[i][j] = lca(stlca[i][j-1], stlca[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1; i<=n; i++) stmin[i][0] = i;
    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            if(in[stmin[i][j-1]] < in[stmin[i+(1<<(j-1))][j-1]]) stmin[i][j] = stmin[i][j-1];
            else stmin[i][j] = stmin[i+(1<<(j-1))][j-1];
        }
    }
    for(int i=1; i<=n; i++) stmax[i][0] = i;
    for(int j=1; j<MAXLOG; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            if(in[stmax[i][j-1]] > in[stmax[i+(1<<(j-1))][j-1]]) stmax[i][j] = stmax[i][j-1];
            else stmax[i][j] = stmax[i+(1<<(j-1))][j-1];
        }
    }
    lg[1] = 0;
    for(int i=2; i<=n; i++) lg[i] = 1+lg[i/2];
    while(q--){
        int l, r;
        cin >> l >> r;
        int mn = minquery(l, r);
        int res1;
        if(mn == l){
            res1 = lcaquery(mn+1, r);
        }
        else if(mn == r){
            res1 = lcaquery(l, mn-1);
        }
        else{
            res1 = lca(lcaquery(l, mn-1), lcaquery(mn+1, r));
        }

        int mx = maxquery(l, r);
        int res2;
        if(mx == l){
            res2 = lcaquery(mx+1, r);
        }
        else if(mx == r){
            res2 = lcaquery(l, mx-1);
        }
        else{
            res2 = lca(lcaquery(l, mx-1), lcaquery(mx+1, r));
        }

        if(depth[res1] >= depth[res2]) cout << mn << " " << depth[res1] << "\n";
        else cout << mx << " " << depth[res2] << "\n";
    }
    return 0;
}