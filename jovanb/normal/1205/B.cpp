#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[1000005];
vector <int> ima[64];
set <pair <int, int>> graf;
set <pair <int, int>> dgraf;

int dist[1000005];

vector <int> vec;

const int INF = 1000000000;

void bfs(int root){
    for(auto c : vec){
        dist[c] = INF;
    }
    dist[root] = 0;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto edge : graf){
            if(edge.first == v){
                if(dist[edge.second] == INF){
                    q.push(edge.second);
                    dist[edge.second] = dist[v] + 1;
                }
            }
            else if(edge.second == v){
                if(dist[edge.first] == INF){
                    q.push(edge.first);
                    dist[edge.first] = dist[v] + 1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        ll x = niz[i];
        int cnt = 0;
        while(x){
            if(x & 1){
                ima[cnt].push_back(i);
            }
            x >>= 1;
            cnt++;
        }
    }
    for(int i=0; i<64; i++){
        if(ima[i].size() >= 3){
            cout << "3\n";
            return 0;
        }
    }
    for(int i=0; i<64; i++){
        if(ima[i].size() == 2){
            dgraf.insert({ima[i][0], ima[i][1]});
            graf.insert({ima[i][0], ima[i][1]});
            vec.push_back(ima[i][0]);
            vec.push_back(ima[i][1]);
        }
    }
    int res = INF;
    for(auto edge : dgraf){
        graf.erase(edge);
        int v = edge.first;
        bfs(v);
        res = min(res, dist[edge.second]+1);
    }
    if(res == INF) cout << -1;
    else cout << res;
    return 0;
}