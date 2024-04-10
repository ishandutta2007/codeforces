#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000009;

int par[100005];
int sz[100005];
int res=1;

int findpar(int v){
    if(par[v] == v) return v;
    return par[v] = findpar(par[v]);
}

void query(int u, int v){
    int a = findpar(u);
    int b = findpar(v);
    if(a == b){res = (res*2)%MOD; return;}
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        query(a, b);
        cout << res-1 << "\n";
    }
    return 0;
}