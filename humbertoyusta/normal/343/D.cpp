#include <bits/stdc++.h>
#define maxn 500005
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,Q,ans[maxn];
vector<int> g[maxn],q[maxn][3];
set<int> cnt[maxn],one;

void dfs(int u,int p){

    for( auto v : q[u][0] )
        one.insert(v);

    for( auto v : g[u] ){

        if( v == p ) continue;

        dfs(v,u);

        if( cnt[v].size() > cnt[u].size() )
            swap( cnt[u] , cnt[v] );

        for( auto i : cnt[v] )
            cnt[u].insert(i);

        cnt[v].clear();
    }

    for( auto i : q[u][1] )
        cnt[u].insert(i);

    for( auto i : q[u][2] ){

        auto it1 = cnt[u].upper_bound(i); it1--;
        auto it2 = one.upper_bound(i); it2--;

        if( *it1 >= *it2 ) ans[i] = 0;
            else ans[i] = 1;
    }

    for( auto v : q[u][0] )
        one.erase(v);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> Q;

    for(int i=1; i<=Q; i++){
        int u, v;
        cin >> u >> v;
        u--;
        q[v][u].push_back(i);
        ans[i] = -1;
    }

    one.insert(-inf);
    for(int i=1; i<=n; i++)
        cnt[i].insert(-inf);

    dfs(1,-1);

    for(int i=1; i<=Q; i++)
        if( ans[i] != -1 )
            cout << ans[i] << '\n';

    return 0;
}