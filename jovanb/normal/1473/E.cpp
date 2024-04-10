#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

vector <pair <int, int>> graf[200005];
ll dist[200005][2][2];

const ll INF = 1000000000000000LL;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    for(int i=1; i<=n; i++){
        dist[i][0][0] = dist[i][0][1] = dist[i][1][0] = dist[i][1][1] = INF;
    }
    dist[1][0][0] = 0;
    set <pair <ll, int>> q;
    q.insert({0, 1});
    while(!q.empty()){
        pair <ll, int> pr = *q.begin();
        q.erase(q.begin());
        int v = pr.second;
        int f = 0, s = 0;
        if(v > n && v <= 2*n){
            f = 1;
            v -= n;
        }
        if(v > 2*n && v <= 3*n){
            s = 1;
            v -= 2*n;
        }
        if(v > 3*n){
            s = f = 1;
            v -= 3*n;
        }
        for(auto tt : graf[v]){
            int c = tt.first;
            int d = tt.second;
            for(int cf=f; cf<=1; cf++){
                for(int cs=s; cs<=1; cs++){
                    ll nd = dist[v][f][s];
                    nd += d;
                    if(cf > f) nd -= d;
                    if(cs > s) nd += d;
                    if(dist[c][cf][cs] > nd){
                        q.erase({dist[c][cf][cs], c+n*cf+2*n*cs});
                        dist[c][cf][cs] = nd;
                        q.insert({dist[c][cf][cs], c+n*cf+2*n*cs});
                    }
                }
            }
        }
    }
    for(int i=2; i<=n; i++){
        cout << dist[i][1][1] << " ";
    }
    return 0;
}