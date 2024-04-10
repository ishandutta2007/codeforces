#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 607;
const ll INF = 1E18;
vector<pair<int,ll> > G[DIM];
ll dist[DIM],mod[DIM*4];
bool vis[DIM];
struct node{
    ll dist;
    int x,y;
};
const bool operator > (const node &a,const node &b){
    return a.dist>b.dist;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<DIM*4;++i)
        mod[i] = i%n;
    for (int i = 1; i <= m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    for (ll i = 0; i < n; ++i) {
        sort(G[i].begin(), G[i].end());
        vector<pair<int, ll> > V;
        int mi = 0;
        for (int j = 1; j < G[i].size(); ++j) {
            if (G[i][mi].second > G[i][j].second)
                mi = j;
        }
        for (int j = mi; j < G[i].size(); ++j)
            V.push_back(G[i][j]);
        for (int j = 0; j < mi; ++j)
            V.push_back(G[i][j]);
        G[i] = V;
    }

    for (ll x = 0; x < n; ++x) {
        for(ll j = 0;j<n;++j){
            dist[j] = INF;
            vis[j] = 0;
        }
        dist[x] = 0;

        while(1){
            int y = -1;
            for(int j = 0;j<n;++j){
                if (vis[j])
                    continue;
                if (y==-1 || dist[y]>dist[j])
                    y = j;
            }
            if (y==-1)
                break;
            vis[y] = 1;
            ll dd = dist[y];
            ll dm = dd%n;
            pair<int, ll> cur = G[y][0];
            int start = mod[G[y][0].first + dm];
            int ptr = 1;
            ll ss = G[y][0].second - 1;
            for (int i = start; i < n; ++i) {
                ++ss;
                while (ptr < G[y].size() && mod[G[y][ptr].first + dm] == i) {
                    if (G[y][ptr].second < ss) {
                        cur = G[y][ptr];
                        ss = G[y][ptr].second;
                    }
                    ++ptr;
                }
                ll ds = ss + dd;
                if (dist[i] > ds) {
                    dist[i] = ds;

                }
            }
            for (int i = 0; i < start; ++i) {
                ++ss;
                while (ptr < G[y].size() && mod[G[y][ptr].first + dm] == i) {
                    if (G[y][ptr].second < ss) {
                        cur = G[y][ptr];
                        ss = G[y][ptr].second;
                    }
                    ++ptr;
                }
                ll ds = ss + dd;
                if (dist[i] > ds) {
                    dist[i] = ds;

                }
            }
        }
        for(ll i = 0;i<n;++i)
            cout<<dist[i]<<' ';
        cout<<endl;
    }


    return 0;
}