#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define vi vector<int>
#define pb push_back
const int N = 4e6 + 10;
vi con[N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool f[N];
bool valid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
inline int get(int i, int j, int m){ return i * m + j;}
int partner[N];
int deg[N];
bool vis[N];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    string s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++) if(s[j] == '*') f[i * m + j] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int node = i * m + j;
            if(!f[node]){
                for(int k = 0; k < 4; k++){
                    int node2 = get(i + dx[k], j + dy[k], m);
                    if(!valid(i + dx[k], j + dy[k], n, m)) continue;
                    if(!f[node2]){
                        con[node].push_back(node2);
                    }
                }
            }
        }
    }
    queue<int> q;
    for(int i = 0; i < n * m; i++){
        deg[i] = con[i].size();
        if(con[i].size() == 1) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(vis[u]) continue;    
        for(int v : con[u]){
            if(!vis[v]){
                deg[v] = 0;
                partner[v] = u;
                partner[u] = v;
                vis[v] = 1;
                vis[u] = 1;
                for(int w : con[v]){
                    if(partner[w]) continue; 
                    deg[w]--; 
                    if(deg[w] == 1) q.push(w);
                }
            }
        }
    }
    for(int i = 0; i < n * m; i++) if(!f[i] && !vis[i]){
        cout << "Not unique";
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int node = get(i, j, m);
            if(f[node]){
                cout << '*';
                continue;
            }
            
            if(partner[node] == get(i + dx[0], j + dy[0], m)) cout << '^';
            else if(partner[node] == get(i + dx[1], j + dy[1], m)) cout << 'v';
            else if(partner[node] == get(i + dx[2], j + dy[2], m)) cout << '<';
            else if(partner[node] == get(i + dx[3], j + dy[3], m)) cout << '>';   
        }
        cout << endl;
    }
}