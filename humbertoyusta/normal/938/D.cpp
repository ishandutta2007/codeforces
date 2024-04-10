#include <bits/stdc++.h>
using namespace std;

struct arc{int nod; long long cost;
bool operator < ( const arc & other ) const { return cost > other.cost; }
};

const int maxn = 200005;
int n,m,u,v;
long long c,dj[maxn],w;
vector<arc> g[maxn];
priority_queue<arc> q;

void dijkstra(){

while(!q.empty()){
    u=q.top().nod;
    c=q.top().cost;
    q.pop();
    if(c>dj[u]) continue;

    for(int i=0; i<g[u].size(); i++){
        v=g[u][i].nod;
        w=g[u][i].cost;

        if(dj[v]>dj[u]+w){
            dj[v]=dj[u]+w;
            q.push((arc){v,dj[v]});
        }
    }

}

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        cin >> u >> v >> c;
        g[u].push_back((arc){v,2*c});
        g[v].push_back((arc){u,2*c});
    }

    for(int i=1; i<=n; i++){
        cin>>c;
        dj[i]=c;
        q.push((arc){i,c});
    }

    dijkstra();

    for(int i=1; i<=n; i++){
        cout<<dj[i]<<' ';
    }

    return 0;
}