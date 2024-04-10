#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[200005];
int gde[200005];
int sz[200005];

int x = 1;
vector <int> graf[200005];

void dfs(int v){
    sz[v] = 1;
    gde[v] = x;
    niz[x++] = v;
    for(auto c : graf[v]){
        dfs(c);
        sz[v] += sz[c];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, q;
    cin >> n >> q;
    int a;
    for(int i=2; i<=n; i++){
        cin >> a;
        graf[a].push_back(i);
    }
    for(int i=1; i<=n; i++){
        sort(graf[i].begin(), graf[i].end());
    }
    dfs(1);
    int k;
    while(q--){
        cin >> a >> k;
        if(sz[a] < k) cout << -1 << "\n";
        else cout << niz[gde[a]+k-1] << "\n";
    }
    return 0;
}