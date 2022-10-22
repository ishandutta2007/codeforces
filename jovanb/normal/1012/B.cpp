#include <bits/stdc++.h>
using namespace std;

int cnt;

bool visited[500005];
vector <int> graf[500005];

void dfs(int v){
    if(visited[v]) return;
    visited[v] = 1;
    for(auto c : graf[v]) dfs(c);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=k; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(n+b);
        graf[b+n].push_back(a);
    }
    for(int i=1; i<=m+n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt-1;
    return 0;
}