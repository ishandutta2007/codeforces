#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[3005];
int dist[3005][3005];

int n;

void bfs(int root){
    for(int i=1; i<=n; i++) dist[root][i] = 5000;
    dist[root][root] = 0;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c : graf[v]){
            if(dist[root][c] > dist[root][v] + 1){
                dist[root][c] = dist[root][v] + 1;
                q.push(c);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int m;
    cin >> n >> m;
    for(int t=1; t<=m; t++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++) bfs(i);
    int s1, f1, l1;
    cin >> s1 >> f1 >> l1;
    int s2, f2, l2;
    cin >> s2 >> f2 >> l2;
    int res = 0;
    if(dist[s1][f1] > l1 || dist[s2][f2] > l2){
        cout << -1;
        return 0;
    }
    res = max(res, m-dist[s1][f1]-dist[s2][f2]);
    for(int s=1; s<=n; s++){
        for(int f=1; f<=n; f++){
            if(min(dist[s1][s]+dist[s][f]+dist[f][f1], dist[f1][s]+dist[s][f]+dist[f][s1]) <= l1 && min(dist[s2][s]+dist[s][f]+dist[f][f2], dist[f2][s]+dist[s][f]+dist[f][s2]) <= l2){
                res = max(res, m-dist[s][f]-min(dist[s1][s]+dist[f][f1], dist[f1][s]+dist[f][s1])-min(dist[s2][s]+dist[f][f2], dist[f2][s]+dist[f][s2]));
            }
        }
    }
    cout << res;
    return 0;
}