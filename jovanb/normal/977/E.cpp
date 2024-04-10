#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ukup = 0;

vector <int> graf[200005];

int ima=0;
bool visited[200005];
int jeste=1;

void dfs(ll v, ll prev){
    visited[v] = 1;
    if(graf[v].size() != 2) jeste = 0;
    for(auto c : graf[v]){
        if(visited[c] && c != prev) ima=1;
        if(!visited[c]) dfs(c, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        ima = 0;
        jeste = 1;
        if(!visited[i]) dfs(i, 0);
        if(jeste && ima) ukup++;
    }
    cout << ukup;
    return 0;
}