#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
vector < int > E[100005];
vector < pii > Ev;
bool used[400005];
int low[100005];

void AddEdge(int x, int y){
    int t = (int)Ev.size();
    Ev.pb({x, y});
    E[x].pb(t);
    E[y].pb(t);
}

vector < int > Cycle;

void DFS(int id){
    for (int &i = low[id]; i < (int)E[id].size(); ++i){
        if (used[E[id][i]]++) continue;
        DFS(Ev[E[id][i]].x + Ev[E[id][i]].y - id);
        Cycle.pb(id);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    REP(m,i){
        int x, y;
        scanf("%d%d", &x, &y), --x, --y;
        AddEdge(x, y);
    }

    vector < int > Nep;
    REP(n,i) if (E[i].size() % 2 == 1) Nep.pb(i);
    REP(Nep.size()/2, i) AddEdge(Nep[2*i], Nep[2*i+1]);
    if ((m + Nep.size()/2) % 2 == 1) AddEdge(0, 0);

    DFS(0);
    printf("%d\n", (int)Cycle.size());
    Cycle.pb(Cycle.front());
    REP(Cycle.size()-1, i) if (i&1) printf("%d %d\n", Cycle[i]+1, Cycle[i+1]+1); else printf("%d %d\n", Cycle[i+1]+1, Cycle[i]+1);
    return 0;
}