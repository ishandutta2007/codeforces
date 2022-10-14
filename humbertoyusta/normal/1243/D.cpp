#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n, m, comp[maxn];
set<int> g[maxn], s;
queue<int> q;

void bfs(int nod,int c){
    q.push(nod);
    comp[nod] = c;
    s.erase(nod);
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        stack<int> p;

        for( auto v : s ){
            if( *g[u].lower_bound(v) != v ){
                q.push(v);
                p.push(v);
                comp[v] = c;
            }
        }

        while( !p.empty() ){
            s.erase(p.top());
            p.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    for(int i=1; i<=n; i++){
        s.insert(i);
        g[i].insert(inf);
    }

    int cc = 0;
    while( !s.empty() )
        bfs( *s.begin() , ++cc );
    cout << cc - 1 << '\n';

    return 0;
}