#include<bits/stdc++.h>
#define maxn 200010
#define f first
#define s second
#define inf 1000000007
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;

int n, Q, ans[maxn], sol, parent[maxn], ran[maxn];
ii q[maxn];
pair<int,ii> edge[maxn];

int find_(int x){
    if( x == parent[x] ) return x;
    return parent[x] = find_( parent[x] );
}

void join(int u,int v){
    u = find_(u), v = find_(v);
    if( u == v ) return;
    sol += ran[u] * ran[v];
    parent[v] = u;
    ran[u] += ran[v];
}

 main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> Q;

    for(int i=1; i<=n; i++ )
        parent[i] = i, ran[i] = 1;

    for(int i=1; i<n; i++)
        cin >> edge[i].s.f >> edge[i].s.s >> edge[i].f;

    sort( edge + 1 , edge + n );

    for(int i=1; i<=Q; i++){
        cin >> q[i].f;
        q[i].s = i;
    }
    q[Q+1].f = inf;
    edge[n].f = inf;

    sort( q + 1 , q + Q + 1 );

    int p = 0;
    for(int i=1; i<=Q; i++){
        while( edge[p].f <= q[i].f ){
            join(edge[p].s.f,edge[p].s.s);
            p++;
        }
        ans[q[i].s] = sol;
    }

    for(int i=1; i<=Q; i++)
        cout << ans[i] << ' ';

    return 0;
}