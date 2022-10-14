#include<bits/stdc++.h>
#define maxn 300005
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int n,o,a,b,w,lv[maxn],p[maxn];
long long res[maxn],lazy[maxn];
vector<int> g[maxn];
vector<ii> q[maxn];

void dfs(int u,long long sum){
    for(auto v : q[u]){
        lazy[lv[u]] += v.s;
        if( lv[u]+v.f+1 < n )
            lazy[lv[u]+v.f+1] -= v.s;
    }
    sum += lazy[lv[u]];
    res[u] = sum;
    for(auto v : g[u])
        if( !lv[v] && p[u] != v ){
            p[v] = u;
            lv[v] = lv[u] + 1;
            dfs(v,sum);
        }
    for(auto v : q[u]){
        lazy[lv[u]] -= v.s;
        if( lv[u]+v.f+1 < n )
            lazy[lv[u]+v.f+1] += v.s;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> n;

    for(int i=1; i<n; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cin >> o;

    for(int i=1; i<=o; i++){
        cin >> a >> b >> w;
        q[a].push_back(ii{b,w});
    }

    lv[1]=1;
    p[1]=1;
    dfs(1,0);

    for(int i=1; i<=n; i++)
        cout << res[i] << ' ';

    return 0;
}