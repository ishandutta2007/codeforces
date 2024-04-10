/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[maxn],ans;
vector<int> g[maxn];
map<int,int> dp[maxn];

void dfs(int u,int p){
    for(auto v : g[u])
        if( v != p )
            dfs(v,u);

    for(auto i : dp[u]){
        for(auto v : g[u]){
            if( v != p ){
                ans = max( ans , dp[u][i.f] + dp[v][i.f] );
                dp[u][i.f] = max( dp[u][i.f] , dp[v][i.f] + 1 );
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        int tmp = a[i];
        for(int j=2; j*j<=tmp; j++){
            if(tmp%j==0) dp[i][j] = 1;
            while(tmp%j==0) tmp/=j;
        }
        if(tmp>1) dp[i][tmp] = 1;
    }

    if( n == 1 && a[1] > 1 ){ cout << 1; return 0; }

    for(int i=1; i<n; i++){
        int aa , bb;
        cin >> aa >> bb;
        g[aa].push_back(bb);
        g[bb].push_back(aa);
    }

    dfs(1,1);

    cout << ans << '\n';

    return 0;
}