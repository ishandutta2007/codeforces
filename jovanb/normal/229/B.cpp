#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

map <int, int> wait[100005];

int dis[100005];
bool bio[100005];
vector <pair <int, int>> graf[100005];
int kad[100005];

const int INF = 2000000000;

int n;

void sp(){
    set <pair <int, int>> pq;
    dis[1] = 0;
    bio[1] = 1;
    pq.insert({0, 1});
    for(int i=2; i<=n; i++) dis[i] = INF;
    while(!pq.empty()){
        int dist1 = pq.begin()->first;
        int v = pq.begin()->second;
        pq.erase({dist1, v});
        bio[v] = 1;
        if(v == n) return;
        for(auto par : graf[v]){
            int c = par.first;
            int dist2 = par.second;
            if(bio[c]) continue;
            int dolazi = dist1+dist2+wait[v][dist1];
            if(dolazi < dis[c]){
                pq.erase({dis[c], c});
                dis[c] = dolazi;
                pq.insert({dis[c], c});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int m;
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        for(int j=1; j<=k; j++) cin >> kad[j];
        for(int j=k; j>=1; j--) wait[i][kad[j]] = 1+wait[i][kad[j]+1];
    }
    sp();
    if(dis[n] == INF) cout << -1;
    else cout << dis[n];
    return 0;
}