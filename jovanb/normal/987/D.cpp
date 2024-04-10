#include <bits/stdc++.h>
using namespace std;

vector <int> disovi[100005];
vector <int> graf[100005];
int tip[100005];
bool visited[100005];

int n;

void bfs(int t){
    memset(visited, 0, sizeof visited);
    queue <pair <int, int>> q;
    for(int i=1; i<=n; i++){
        if(tip[i] == t){
            q.push({i, 0});
            visited[i] = 1;
        }
    }
    while(!q.empty()){
        int tren = q.front().first;
        int dis = q.front().second;
        q.pop();
        disovi[tren].push_back(dis);
        for(auto c : graf[tren]){
            if(!visited[c]){
                visited[c] = 1;
                q.push({c, dis+1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int m, k, s;
    cin >> n >> m >> k >> s;
    for(int i=1; i<=n; i++) cin >> tip[i];
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=k; i++){
        bfs(i);
    }
    for(int i=1; i<=n; i++){
        sort(disovi[i].begin(), disovi[i].end());
        int z=0;
        for(int j=0; j<s; j++) z += disovi[i][j];
        cout << z << " ";
    }
    return 0;
}