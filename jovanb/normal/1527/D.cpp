#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int tjm;

int par[200005][20];
ll sz[200005];
int in[200005];
int out[200005];
int h[200005];
vector <int> graf[200005];

void dfs(int v, int p){
    par[v][0] = p;
    in[v] = ++tjm;
    sz[v] = 1;
    h[v] = h[p] + 1;
    for(int j=1; j<18; j++) par[v][j] = par[par[v][j-1]][j-1];
    for(auto c : graf[v]){
        if(c != p){
            dfs(c, v);
            sz[v] += sz[c];
        }
    }
    out[v] = tjm;
}

bool is_parent(int a, int b){
    return (a == 0) || (in[a] <= in[b] && out[b] <= out[a]);
}

bool imapath;

int lca(int a, int b){
    if(is_parent(a, b)) return a;
    for(int j=17; j>=0; j--){
        if(!is_parent(par[a][j], b)) a = par[a][j];
    }
    return par[a][0];
}

int calc_dst(int a, int b){
    int x = lca(a, b);
    return h[a] + h[b] - 2*h[x];
}

bool naputu(int a, int b, int c){
    return calc_dst(a, b) == calc_dst(a, c) + calc_dst(c, b);
}

int k1, k2;
int sleddole;

int uradi(int a, int b){
    for(auto c : graf[a]){
        if(!is_parent(c, a) && is_parent(c, b)) return c;
    }
    return 0;
}

void dodaj(int x){
    int pk1 = k1;
    if(naputu(k1, k2, x)) return;
    if(naputu(k1, x, k2)){
        k2 = x;
        return;
    }
    if(naputu(k2, x, k1)){
        k1 = x;
        return;
    }
    imapath = 0;
    return;
}

ll res2;

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        graf[i].clear();
    }
    imapath = 1;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        a++;
        b++;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    tjm = 0;
    dfs(1, 0);
    k1 = 1, k2 = 1, sleddole = 1;
    ll res1 = 0;
    for(auto c : graf[1]) res1 += sz[c]*(sz[c]-1)/2;
    cout << res1 << " ";
    k2 = 2;
    for(auto c : graf[1]) if(is_parent(c, k2)) sleddole = c;
    vector <ll> vals;
    for(auto c : graf[1]){
        ll gg = sz[c];
        if(c == sleddole) gg -= sz[2];
        vals.push_back(gg);
    }
    res2 = 0;
    ll sum2 = 1;
    for(auto c : vals){
        res2 += sum2*c;
        sum2 += c;
    }
    cout << res2 << " ";
    for(int k=3; k<=n+1; k++){
        if(!imapath){
            cout << "0 ";
            continue;
        }
        dodaj(k-1);
        if(!imapath){
            cout << "0 ";
            continue;
        }
        if(naputu(k1, k2, k)){
            cout << "0 ";
            continue;
        }
        //cout << endl;
        //cout << k1 << " " << k2 << " " << imapath << endl;
        ll prvi, drugi;
        drugi = sz[k2];
        if(k < n+1 && is_parent(k2, k)){
            drugi -= sz[k];
        }
        if(k1 == 1){
            prvi = n - sz[sleddole];
            if(k < n+1 && !is_parent(sleddole, k)){
                prvi -= sz[k];
            }
        }
        else{
            prvi = sz[k1];
            if(k < n+1 && is_parent(k1, k)){
                prvi -= sz[k];
            }
        }
        cout << prvi*drugi << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}