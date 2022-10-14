#include<bits/stdc++.h>
#define maxn 200010
#define f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double Ld;
typedef pair<int,int> ii;

int n, subt[maxn], p[maxn];
vector<int> g[maxn];
ll res, ans;

void dfs1(int u){
    subt[u]++;
    for( auto v : g[u] )
        if( p[u] != v ){
            p[v] = u;
            dfs1(v);
            subt[u] += subt[v];
        }
    res += subt[u];
}

void dfs2(int u){

    if( u != 1 ){
        res -= subt[p[u]];
        res += n - subt[u];
    }

    ans = max( ans , res - subt[u] + n );

    for( auto v : g[u] )
        if( v != p[u] )
            dfs2(v);

    if( u != 1 ){
        res += subt[p[u]];
        res -= n - subt[u];
    }
}

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n;

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    p[1] = 1;

    dfs1(1);

    dfs2(1);

    cout << ans << '\n';

    return 0;
}