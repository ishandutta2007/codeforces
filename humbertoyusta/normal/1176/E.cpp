#include <bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,m,tc,mk[maxn],c[maxn],cnt[2];
vector<int> g[maxn],ans;

void dfs(int u,bool val){
    cnt[val]++;
    mk[u] = 1, c[u] = val;
    for( auto v : g[u] )
        if( !mk[v] )
            dfs(v,!val);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n >> m;

        ans.clear();
        for(int i=0; i<=n; i++)
            mk[i] = 0;
        for(int i=0; i<=n; i++)
            c[i] = 0;
        cnt[0] = cnt[1] = 0;

        for(int i=1; i<=n; i++)
            g[i].clear();
        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1,1);

        if( cnt[0] >= cnt[1] ){
                for(int i=1; i<=n; i++)
                    if( c[i] == 1 )
                        ans.push_back(i);
        }
        else{
            for(int i=1; i<=n; i++)
                if( c[i] == 0 )
                    ans.push_back(i);
        }

        cout << ans.size() << '\n';
        for( auto i : ans )
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}