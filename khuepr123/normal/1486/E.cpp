#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 10200005;
const ll oo = 1e18 + 7;
int n, a[maxN], m;
int x, y, z, k;

vector<ii> vc[maxN];
int dist[maxN];

void put(int n1, int n2, int w){
    vc[n1 * 51].pb(ii(0, n2 * 51 + w));
    for1(i, 1, 50){
        vc[n1 * 51 + i].pb(ii((i + w) * (i + w), n2 * 51));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int cnt = n;
    for1(i, 1, m){
        cin >> x >> y >> z;
        put(x, y, z);
        put(y, x, z);
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for1(i, 0, maxN - 1){
        dist[i] = mod;
    }
    dist[51] = 0;
    pq.push(ii(0, 51));
    while(!pq.empty()){
        ii pr = pq.top(); pq.pop();
        if(pr.fi == dist[pr.se]){
            for(ii child : vc[pr.se]){
                if(pr.fi + child.fi < dist[child.se]){
                    dist[child.se] = pr.fi + child.fi;
                    pq.push(ii(dist[child.se], child.se));
                }
            }
        }
    }
    for1(i, 1, n){
        if(dist[i * 51] == mod) cout << "-1 ";
        else cout << dist[i * 51] << " ";
    }
}