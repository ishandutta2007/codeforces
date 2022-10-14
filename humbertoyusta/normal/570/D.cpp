#include <bits/stdc++.h>
#define maxn 500010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,Q,ans[maxn],lv[maxn];
string s;
vector<int> g[maxn];
map<int,int> cnt[maxn];
vector<ii> q[maxn];

void dfs(int u){

    for( auto v : g[u] ){
        lv[v] = lv[u] + 1;
        dfs(v);
    }

    for( auto v : g[u] ){
        if( cnt[v].size() > cnt[u].size() )
            swap( cnt[u] , cnt[v] );
        for( auto i : cnt[v] )
            cnt[u][i.f] ^= i.s;
        cnt[v].clear();
    }
    cnt[u][lv[u]] ^= ( 1 << int( s[u-1] - 'a' ) );

    for( auto i : q[u] ){
        if( __builtin_popcount( cnt[u][i.f] ) <= 1 ) ans[i.s] = 1;
            else ans[i.s] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> Q;

    for(int i=2; i<=n; i++){
        int u;cin >> u;
        g[u].push_back(i);
    }

    cin >> s;

    for(int i=1; i<=Q; i++){
        int u, v;
        cin >> u >> v;
        q[u].push_back({v,i});
    }

    lv[1] = 1;
    dfs(1);

    for(int i=1; i<=Q; i++)
        if( ans[i] ) cout << "Yes\n";
            else cout << "No\n";

    return 0;
}