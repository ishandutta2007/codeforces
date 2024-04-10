#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n,color[maxn],has[maxn],dom[maxn],bigc;
vector<int> g[maxn];
map<int,int> cnt[maxn];

void dfs(int u,int p){

    int mx, bigc; mx = bigc = -1;
    for( auto v : g[u] )
        if( v != p ){
            dfs(v,u);
            if( cnt[v].size() > mx )
                mx = cnt[v].size() , bigc = v;
        }

    if( bigc != -1 ){
        swap( cnt[u] , cnt[bigc] );
        dom[u] = dom[bigc];
        has[u] = has[bigc];
    }

    cnt[u][color[u]]++;
    if( cnt[u][color[u]] == has[u] ){ dom[u] += color[u]; }
    if( cnt[u][color[u]] > has[u] ){ has[u] = cnt[u][color[u]], dom[u] = color[u]; }

    for( auto v : g[u] )
        if( v != p && v != bigc ){
            for( auto i : cnt[v] ){
                cnt[u][i.f] += i.s;
                if( cnt[u][i.f] == has[u] ){ dom[u] += i.f; }
                if( cnt[u][i.f] > has[u] ){ has[u] = cnt[u][i.f], dom[u] = i.f; }
            }
            cnt[v].clear();
        }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> color[i];

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);

    for(int i=1; i<=n; i++)
        cout << dom[i] << ' ';

    return 0;
}