#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll res[1000005];
ll bit[1000005];
vector <int> graf[1000005];
vector <pair <int, int>> vec[1000005];

int n;

void updbit(int x, ll val){
    while(x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

ll getbit(int x){
    ll r=0;
    while(x){
        r += bit[x];
        x -= x & -x;
    }
    return r;
}

bool visited[1000005];

void dfs(int v, int depth){
    visited[v] = 1;
    for(auto par : vec[v]){
        int k = par.first;
        int val = par.second;
        updbit(min(n, k+depth), val);
    }
    res[v] = getbit(n)-getbit(depth-1);
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c, depth+1);
    }
    for(auto par : vec[v]){
        int k = par.first;
        int val = par.second;
        updbit(min(n, k+depth), -val);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int m;
    cin >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    dfs(1, 1);
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}