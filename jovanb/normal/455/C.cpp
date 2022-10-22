#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;

int vel[300005];
bool visited[300005];
bool visited1[300005];
bool visited2[300005];

int maxdis = 0;
int par[300005];
int tr;
int sz;
int siz[300005];

vector <int> graf[300005];

int rut(int v){
    if(par[v] == v) return v;
    return par[v] = rut(par[v]);
}

void dfs2(int v, int dis){
    visited2[v] = true;
    if(dis > maxdis) maxdis = dis;
    for(auto c : graf[v]){
        if(!visited2[c]){
            dfs2(c, dis+1);
        }
    }
}

void dfs1(int v, int dis){
    visited1[v] = true;
    if(dis > maxdis){
        tr = v, maxdis = dis;
    }
    for(auto c : graf[v]){
        if(!visited1[c]){
            dfs1(c, dis+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        par[i] = i;
        siz[i] = 1;
        vel[i] = 0;
    }
    int x, a, b;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        a = rut(a);
        b = rut(b);
        if(a == b) continue;
        if(siz[a] < siz[b]) swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
    }
    for(int i=1; i<=n; i++){
        int j = rut(i);
        if(!visited1[j]){
            maxdis = 0;
            tr = j;
            dfs1(j, 0);
            maxdis = 0;
            dfs2(tr, 0);
            vel[j] = maxdis;
        }
    }
    while(q--){
        cin >> x;
        if(x == 1){
            cin >> a;
            a = rut(a);
            cout << vel[a] << "\n";
        }
        else{
            cin >> a >> b;
            a = rut(a);
            b = rut(b);
            if(a == b) continue;
            if(siz[a] < siz[b]) swap(a, b);
            siz[a] += siz[b];
            vel[a] = max(((vel[a]+1)/2+(vel[b]+1)/2+1), max(vel[a], vel[b]));
            par[b] = a;
        }
    }
    return 0;
}