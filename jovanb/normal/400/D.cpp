#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool visited[100005];
vector <int> svi;
int ima[100005];
int dis[505][505];
int tip[100005];
vector <int> graf[1000005];
int sz[505];

void dfs(int v){
    visited[v] = 1;
    ima[tip[v]]++;
    svi.push_back(tip[v]);
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c);
    }
}

const int INF = 1000000000;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    int tren=0;
    for(int i=1; i<=k; i++){
        cin >> sz[i];
        for(int j=tren+1; j<=tren+sz[i]; j++) tip[j] = i;
        tren += sz[i];
    }
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0){
            graf[a].push_back(b);
            graf[b].push_back(a);
        }
        dis[tip[a]][tip[b]] = min(dis[tip[a]][tip[b]], c);
        dis[tip[b]][tip[a]] = min(dis[tip[b]][tip[a]], c);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            for(auto c : svi){
                if(sz[c] != ima[c]){cout << "No"; return 0;}
            }
            for(auto c : svi) ima[c] = 0;
            svi.clear();
        }
    }
    cout << "Yes\n";
    for(int x=1; x<=k; x++){
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                dis[i][j] = min(dis[i][j], dis[i][x]+dis[x][j]);
            }
        }
    }
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            if(dis[i][j] == INF) cout << "-1 ";
            else cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}