#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1000000007;

// FENWICK

int fenwick[MAXN];
void update(int pos, int delta){
    for(;pos < MAXN; pos+=pos&-pos)fenwick[pos]+=delta;
}
int query(int pos){
    int res = 0;
    for(; pos>0; pos-=pos&-pos)res+=fenwick[pos];
    return res;
}

// DSU

int uf[MAXN], rnk[MAXN];

int find(int a){
    if(uf[a]!=a)uf[a]=find(uf[a]);
    return uf[a];
}

void dsunion(int a, int b){
    a = find(a); b = find(b);
    if(rnk[a]<rnk[b])swap(a,b);
    rnk[a]=max(rnk[a],rnk[b]+1);
    uf[b]=a;
}

// FASTEXP

ll fexp(ll b, int e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN];
ll bin (ll a, ll b){
    return (((fact[a]*inv(fact[b]))%MOD)*inv(fact[a-b]))%MOD;
}

void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
}

ll N; int a,b, centroid;
vi adj[MAXN];
ll ans; bool vis[MAXN];

int dfs(int node){
    ll k = 1;
    vis[node] = 1;
    for(auto x: adj[node]){
        if(!vis[x])k += dfs(x);
    }
    ans += min(k,N-k);
    //cout << "node k "<< node << " "<<k<<endl;
    return k;
}

int kek(int node){
    vis[node] = 1;
    int m = 0, s = 1, t;
    for(auto x: adj[node]){
        if(!vis[x]){
            t = kek(x);
            s += t;
            m = max(m,t);
        }
    }
//    cout << "node m s "<<node << " "<<m << " "<<s<<endl;
    if(m <= N/2 && s >= N/2)centroid = node;
    return s;
}

vi order;

void dfss(int node){
    vis[node] = 1;
    order.pb(node);
    for(auto x: adj[node]){
        if(!vis[x])dfss(x);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    cout << 2*ans<<"\n";
    for(int i = 1; i <= N; i++)vis[i] = 0;
    kek(1);
//    cout << centroid << "cent\n";
    for(int i = 1; i <= N; i++)vis[i] = 0;
    dfss(centroid);
    vi ris(N);
    for(int i = 0; i < N; i++){
        ris[order[i]-1] = order[(i+N/2)%N];
    }
    for(auto x: ris)cout << x << " ";
    return 0;
}