#include<bits/stdc++.h>
#define maxn 200010
#define mod 1000000007
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;

int n,u,v,w,K,cont;
int comp[maxn],have[maxn];
vector<int> g[maxn];

ll pot(ll b,int e){
    if( e == 0 ) return 1;
    if( e % 2 == 1 ) return ( pot(b,e-1) * b ) % mod;
    ll pa = pot(b,e/2);
    return ( pa * pa ) % mod;
}

void dfs(int u,int c){
    comp[u] = c;
    for(auto v : g[u])
        if( !comp[v] )
            dfs(v,c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;

    for(int i=1; i<n; i++){
        cin >> u >> v >> w;
        if( !w ){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    for(int i=1; i<=n; i++)
        if(!comp[i])
            dfs(i,++cont);

    for(int i=1; i<=n; i++){
        have[comp[i]]++;
    }

    ll ans = pot(n,K);

    for(int i=1; i<=cont; i++){
        ans = ( ans + mod - pot(have[i],K) ) % mod;
    }

    cout << ans << '\n';

    return 0;
}