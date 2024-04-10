#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int g, r;
int x[20005];
 
int hes(int a, int b){
    return 2000*a+b;
}
 
queue<pair<ll, int> > q;
//set <pair <int, pair <int, int>>> q;
 
const int INF = 2000000000;
 
int res = INF;
 
int dist[10005][1005];
 
int w, n;
 
bool nema(int i, int j){
    if(j < i) return 0;
    return j <= g;
}
 
void dijkstra(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<g+r; j++){
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    q.push({0, hes(1, 0)});
    while(!q.empty()){
        auto m = q.front();
        q.pop();
        int i = m.second/2000;
        int j = m.second%2000;
        if(-dist[i][j] != m.first) continue;
        if(i == n) res = min(res, dist[i][j]);
        //cout << dis << " " << m.second.first << " " << m.second.second << endl;
        if(j == g){
            if(dist[i][0] > dist[i][j]+(r+g-j)){
                dist[i][0] = dist[i][j]+(r+g-j);
                q.push({-dist[i][0], hes(i, 0)});
            }
            continue;
        }
        int k;
        if(i > 1){
            k = (j+x[i]-x[i-1])%(g+r);
            if(nema(j, k) && x[i]-x[i-1] <= g){
                if(dist[i-1][k] > dist[i][j]+x[i]-x[i-1]){
                    dist[i-1][k] = dist[i][j]+x[i]-x[i-1];
                    q.push({-dist[i-1][k], hes(i-1, k)});
                }
            }
        }
        if(i < n){
            k = (j+x[i+1]-x[i])%(g+r);
            if(nema(j, k) && x[i+1]-x[i] <= g){
                if(dist[i+1][k] > dist[i][j]+x[i+1]-x[i]){
                    dist[i+1][k] = dist[i][j]+x[i+1]-x[i];
                    q.push({-dist[i+1][k], hes(i+1, k)});
                }
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    cin >> w >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }
    sort(x+1, x+1+n);
    cin >> g >> r;
    dijkstra();
    if(res == INF){
        cout << -1;
        return 0;
    }
    cout << res;
    return 0;
}