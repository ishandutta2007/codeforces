#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int cnt;
int col[300005];
vector <int> graf[300005];
vector <int> vec[300005];
int banned[300005];

void dfs(int v, int parent){
    queue <int> q;
    for(auto c : vec[v]){
        if(col[c]) banned[col[c]] = 1;
        else q.push(c);
    }
    int tren = 1;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        while(banned[tren]) tren++;
        col[c] = tren;
        banned[tren] = 1;
    }
    cnt = max(cnt, tren);
    for(auto c : vec[v]) banned[col[c]] = 0;
    for(auto c : graf[v]){
        if(c == parent) continue;
        dfs(c, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        while(x--){
            int a;
            cin >> a;
            vec[i].push_back(a);
        }
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    cout << cnt << "\n";
    for(int i=1; i<=m; i++){
        if(col[i]) cout << col[i] << " ";
        else cout << 1 << " ";
    }
    return 0;
}