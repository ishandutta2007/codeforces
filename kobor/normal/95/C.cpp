//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=1e3+5;

int n, m;
ll dist[N];
int dale[N], koszt[N];
vii G1[N], G2[N];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

void dijkstra(int start){
    memset(dist, inf, sizeof(dist));
    dist[start]=0;
    q.push({0, start});
    while(!q.empty()){
        auto v=q.top();
        q.pop();
        if(dist[v.nd]<v.st) continue;
        for(auto &x: G1[v.nd]){
            if(dist[x.st]>v.st+x.nd){
                dist[x.st]=v.st+x.nd;
                q.push({dist[x.st], x.st});
            }
        }
    }
}

void solve(){
    int st, met, a, b, c;
    cin>>n>>m>>st>>met;
    FOR(i, 1, m){
        cin>>a>>b>>c;
        G1[a].pb({b, c});
        G1[b].pb({a, c});
    }
    FOR(i, 1, n) cin>>dale[i]>>koszt[i];
    FOR(i, 1, n){
        dijkstra(i);
        FOR(j, 1, n) if(dist[j]<=dale[i]) G2[i].pb({j, koszt[i]});
    }
    FOR(i, 1, n) swap(G1[i], G2[i]);
    dijkstra(st);
    cout<<(dist[met]==INF ? -1 : dist[met])<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}