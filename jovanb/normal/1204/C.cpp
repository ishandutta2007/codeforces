#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

//bool ima[105][105][105];

int wrong;

int dist[105][105];

const int INF = 1000000000;

vector <int> graf[105];

int n;

/*void bfs(int root){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[root] = 0;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c : graf[v]){
            if(c == wrong) continue;
            if(dist[c] > dist[v]+1){
                dist[c] = dist[v]+1;
                q.push(c);
            }
        }
    }
}*/

int niz[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        //dist[i][i] = 0;
        string s;
        cin >> s;
        for(int j=1; j<=n; j++){
            if(s[j-1] == '1'){
                //graf[i].push_back(j);
                dist[i][j] = 1;
            }
            else dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    /*for(int i=1; i<=n; i++){
        ima[i][i][i] = 1;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(j == k || i == k) continue;
                //cout << "test " << i << " " << j << " " << k << endl;
                wrong = 0;
                bfs(i);
                int g = dist[j];
                wrong = k;
                bfs(i);
                //if(i == 1 && j == 4 && k == 3) cout << g << " " << dist[j] << endl;
                if(g == dist[j]){
                    ima[i][j][k] = 1;
                }
                else cout << i << " " << j << " " << k << endl;
            }
        }
    }*/
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int m;
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> niz[i];
    }
    vector <int> res;
    res.push_back(niz[1]);
    res.push_back(niz[2]);
    for(int i=3; i<=m; i++){
        int x = res.size();
        if(dist[res[x-2]][niz[i]] != dist[res[x-2]][res[x-1]] + dist[res[x-1]][niz[i]]){
            res.push_back(niz[i]);
        }
        else{
            res.pop_back();
            res.push_back(niz[i]);
        }
    }
    cout << res.size() << "\n";
    for(auto c : res) cout << c << " ";
    return 0;
}