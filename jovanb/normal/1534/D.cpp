#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 2000;

int dist[MAXN+5][MAXN+5];

int n;

void pitaj(int v){
    cout << "? " << v << endl;
    for(int i=1; i<=n; i++) cin >> dist[v][i];
}

vector <int> graf[MAXN+5];
bool bio[MAXN+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    pitaj(1);
    int np = 0, p = 0;
    for(int i=1; i<=n; i++){
        if(dist[1][i]%2){
            np++;
        }
        else p++;
    }
    queue <pair <int, int>> q;
    if(np >= p){
        q.push({1, 0});
        bio[1] = 1;
    }
    else{
        for(int i=1; i<=n; i++){
            if(dist[1][i] == 1){
                //graf[i].push_back(1);
                //graf[1].push_back(i);
                q.push({i, 0});
                bio[i] = 1;
            }
        }
    }
    while(!q.empty()){
        int v = q.front().first;
        int par = q.front().second;
        q.pop();
        if(v != 1) pitaj(v);
        bio[v] = 1;
        for(int i=1; i<=n; i++){
            if(dist[v][i] == 1){
                graf[i].push_back(v);
                graf[v].push_back(i);
            }
            if(dist[v][i] == 2 && (par == 0 || dist[par][i] > dist[v][i]) && !bio[i]){
                q.push({i, v});
                bio[i] = 1;
            }
        }
    }
    cout << "!\n";
    for(int i=1; i<=n; i++){
        for(auto c : graf[i]) if(c > i) cout << i << " " << c << endl;
    }
    return 0;
}