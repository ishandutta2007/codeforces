#include<bits/stdc++.h>
#define maxn 200010
#define f first
#define s second
#define ii pair<int,int>
using namespace std;

long long subt[maxn];
long long minans, maxans, dp[maxn];
vector<ii> g[maxn];
int n;

void dfs(int u,int p){
    subt[u] = 1;

    for( auto v : g[u] )
        if( v.f != p ){
            dfs(v.f,u);
            subt[u] += subt[v.f];
            if( subt[v.f] & 1 ) minans += v.s;
            maxans += v.s * min( subt[v.f] , 2 * n - subt[v.f] );
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){

        cin >> n;
        for(int i=1; i<=2*n; i++)
            g[i].clear();
        for(int i=1; i<2*n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        dfs(1,1);

        cout << minans << ' ' << maxans << '\n';
        minans = maxans = 0;
    }
    return 0;
}