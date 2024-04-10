#include <bits/stdc++.h>
using namespace std;

int depth[1000005];
int par[1000005][20];

int p = 2;
int d = 3;
int diameter = 2;
int n = 4;

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int i=19; i>=0; i--){
        if(depth[a]-(1 << i) >= depth[b]){
            a = par[a][i];
        }
    }
    if(a == b) return a;
    //cout << "e za ovaj lca je a = " << a << endl;
    for(int i=19; i>=0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

void add(int pr, int v){
    par[v][0] = pr;
    for(int i=1; i<=19; i++){
        par[v][i] = par[par[v][i-1]][i-1];
    }
    depth[v] = depth[pr]+1;
    int lc = lca(v, p);
    if(depth[v]+depth[p]-2*depth[lc] > diameter){
        diameter = depth[v]+depth[p]-2*depth[lc];
        d = v;
    }
    lc = lca(v, d);
    if(depth[v]+depth[d]-2*depth[lc] > diameter){
        diameter = depth[v]+depth[d]-2*depth[lc];
        p = v;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    par[2][0] = 1;
    par[3][0] = 1;
    par[4][0] = 1;
    depth[1] = 1;
    depth[2] = depth[3] = depth[4] = 2;
    while(q--){
        int x;
        cin >> x;
        add(x, ++n);
        add(x, ++n);
        cout << diameter << "\n";
    }
    return 0;
}