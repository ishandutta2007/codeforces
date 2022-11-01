#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define FORll(a,b,c) for (ll c = (ll)(a); c < (ll)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void operator+=(vector < int > &a, const vector < int > &b){
    for (auto x : b) a.pb(x);
    sort(a.begin(), a.end());
    a.resize(10);
}

void makemax(int &a, int b){if (a < b) a = b;}

int n, m, q;
vector < int > E[100005];

vector < int > st[100005];
vector < int > qu[17][100005];

vector < int > Ecen[100005];
int Root;
bool cBio[100005];
int Size[100005];
int Val[100005];
int Dep[100005];
void cDFS(int id, int p){
    Size[id] = 1;
    Val[id] = 0;
    for (auto x : E[id]) if (!cBio[x] && x != p){
        cDFS(x, id);
        Size[id] += Size[x];
        makemax(Val[id], Size[x]);
    }
}
int S;
int cDFS2(int id, int p){
    makemax(Val[id], S - Size[id]);
    int best = id;
    for (auto x : E[id]) if (!cBio[x] && x != p){
        int y = cDFS2(x, id);
        if (Val[best] > Val[y]) best = y;
    } return best;
}
void cDFS3(int id, int p, int dep){
    if (id == p) qu[dep][id].resize(10, 1e9);
    else qu[dep][id] += st[id];
    for (auto x : E[id]) if (!cBio[x] && x != p){
        if (id != p){
            qu[dep][x] += qu[dep][id];
        } cDFS3(x, id, dep);
    }
}
int Decompose(int id, int dep = 0){
    cDFS(id, id);
    S = Size[id]; //TRACE(dep _ S);
    int CR = cDFS2(id, id); //TRACE(dep _ Val[50]);
    cDFS3(CR, CR, dep);
    cBio[CR] = true;
    Dep[CR] = dep;
    for (auto x : E[CR]) if (!cBio[x]) Ecen[CR].pb(Decompose(x, dep+1));
    return CR;
}

int LCA[17][100005];

int lca(int a, int b){
    if (Dep[a] < Dep[b]) swap(a, b);
    int t = Dep[a] - Dep[b];
    REP(17,i) if ((t>>i)&1) a = LCA[i][a];
    for (int i = 16; i >= 0; --i) if (LCA[i][a] != LCA[i][b]) a = LCA[i][a], b = LCA[i][b];
    if (a == b) return a;
    return LCA[0][a];
}

int main(){
    cin >> n >> m >> q;
    REP(n-1,i){
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        E[a].pb(b);
        E[b].pb(a);
    }
    REP(n,i) st[i].resize(10, 1e9);
    REP(m,i){
        int x;
        scanf("%d", &x), --x;
        REP(10,j) if (st[x][j] > i){st[x][j] = i; break;}
    }
    Root = Decompose(0);
    REP(n,i) for (auto x : Ecen[i]) LCA[0][x] = i;
    FOR(1,17,i) REP(n,j) LCA[i][j] = LCA[i-1][LCA[i-1][j]];

    //REP(n,i) REP(10,j) TRACE(i _ qu[0][i][j]);

    REP(q,ttt){
        int v, u, a;
        scanf("%d%d%d", &v, &u, &a), --v, --u;
        int t = lca(u, v);
        vector < int > sol = st[t];
        sol += qu[Dep[t]][v];
        sol += qu[Dep[t]][u];
        while (!sol.empty() && (sol.back() > 1e6 || sol.size() > a)) sol.pop_back();
        printf("%d ", (int)sol.size());
        for (auto x : sol) printf("%d ", x+1);
        printf("\n");
    }

    return 0;
}