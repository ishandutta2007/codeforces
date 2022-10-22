#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <pair <int, int>> queries[100005];
vector <pair <int, int>> tl;
vector <int> graf[100005];
int koji[100005];
int res[100005];
int par[100005];
int sz[100005];
int in[100005];
int out[100005];
int prnt[100005];

int pr(int x){
    if(par[x] == x) return x;
    return par[x] = pr(par[x]);
}

void dsu(int a, int b){
    int a1 = pr(a);
    int b1 = pr(b);
    if(a1 == b1) return;
    if(sz[a1] > sz[b1]) swap(a1, b1);
    sz[b1] += sz[a1];
    par[a1] = b1;
}

bool connected(int a, int b){
    int a1 = pr(a);
    int b1 = pr(b);
    return a1 == b1;
}

int tren;

void dfs(int v){
    in[v] = ++tren;
    for(auto c : graf[v]) dfs(c);
    out[v] = ++tren;
}

bool parent(int a, int b){
    return in[a] <= in[b] && out[b] <= out[a];
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    int r=0;
    int cnt=0;
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            graf[y].push_back(x);
            prnt[x] = y;
            tl.push_back({x, y});
        }
        if(t == 2){
            int x;
            cin >> x;
            tl.push_back({0, x});
        }
        if(t == 3){
            int x, i;
            cin >> x >> i;
            queries[i].push_back({x, ++r});
        }
    }
    for(int i=1; i<=n; i++){
        if(!prnt[i]) dfs(i);
    }
    cnt=0;
    for(auto par : tl){
        int a = par.first;
        int b = par.second;
        if(a){
            dsu(a, b);
        }
        else{
            cnt++;
            for(auto c : queries[cnt]){
                if(parent(c.first, b) && connected(c.first, b)) res[c.second] = 1;
                else res[c.second] = -1;
            }
        }
    }
    for(int i=1; i>0; i++){
        if(res[i] == 1) cout << "YES\n";
        else if(res[i] == -1) cout << "NO\n";
        else break;
    }
    return 0;
}