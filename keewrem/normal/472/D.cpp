#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;
const int MAXN = 2010;
int m[MAXN][MAXN], d[MAXN][MAXN];
int r;
vector<pii> adj[MAXN];
bool vis[MAXN];
int uf[MAXN], sz[MAXN];

int find(int a){
    return uf[a] == a?a:uf[a]=find(uf[a]);
}
bool uni(int a, int b){
    a = find(a); b = find(b);
    if(a == b)return 0;
    if(sz[a] < sz[b])swap(a,b);
    sz[a]+=sz[b];
    uf[b] = a;
    return 1;
}

void dfs(int n, int s){
    vis[n] = 1;
    d[r][n] = s;
    for(auto x: adj[n]){
        if(!vis[x.fi])dfs(x.fi,s+x.se);
    }
}
bool solve(){
    int N; scanf("%d", &N);
    FOR(i,N)FOR(j,N)scanf("%d", &m[i][j]);
    vector<array<int,3>> v;
    FOR(i,N)FOR(j,N){
        if((i != j) != (bool)m[i][j])return 0;
        if(i != j)v.pb({m[i][j],i,j});
        if(m[i][j] != m[j][i])return 0;
    }
    iota(uf,uf+MAXN,0);
    sort(all(v));
    for(auto x: v){
        if(uni(x[1],x[2])){
            adj[x[1]].pb({x[2],x[0]});
            adj[x[2]].pb({x[1],x[0]});
        }
    }
    FOR(i,N){
        FOR(j,N)vis[j] = 0;
        r = i;
        dfs(i,0);
    }
    FOR(i,N)FOR(j,N){
        //cout << m[i][j] << " \n"[j == N-1];
        if(d[i][j] != m[i][j])return 0;
    }return 1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    if(solve())cout << "YES\n";
    else cout << "NO\n";
    return 0;
}