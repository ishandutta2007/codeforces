#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>
#include <set>
#include <cstring>
#include <map>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define _T1 id * 2, lo, mid
#define _T2 id * 2 + 1, mid + 1, hi
#define pll pair < ll, ll >

using namespace std;

void NO(){printf("No\n"); exit(0);}

pii operator+(pii a, pii b){return {a.x + b.x, a.y + b.y};}
void operator+=(pii &a, pii b){a = a + b;}

class UF{
public:
    int gr[200005];
    UF(){REP(200005,i) gr[i] = i;}
    int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
    void join(int a, int b){gr[un(a)] = un(b);}
    void joinD(int a, int b, int *d){a = un(a), b = un(b); if (d[a] < d[b]) swap(a, b); gr[un(a)] = un(b);}
} UF1, UF2;

int n, m, q;
vector < int > E[200005];
vector < int > E2[200005];
vector < int > E3[200005];

bool bio[200005];
int dep[200005];
void DFS(int id, int p = -1){
    bio[id] = true;
    for (auto x : E[id]) if (x != p){
        if (bio[x]) UF2.joinD(x, id, dep);
        else {
            dep[x] = dep[id] + 1;
            DFS(x, id);
            if (dep[UF2.un(x)] <= dep[id]) UF2.joinD(x, id, dep);
        }
    }
}

int LCA[20][200005];
void DFS2(int id, int p){
    LCA[0][id] = p;
    bio[id] = true;
    for (auto x : E2[id]) if (x != p){
        E3[id].pb(x);
        dep[x] = dep[id] + 1;
        DFS2(x, id);
    }
}
int lca(int a, int b){
    if (dep[a] < dep[b]) swap(a, b);
    int t = dep[a] - dep[b];
    REP(20,i) if ((t >> i) & 1) a = LCA[i][a];
    for (int i = 19; i >= 0; --i) if (LCA[i][a] != LCA[i][b]) a = LCA[i][a], b = LCA[i][b];
    if (a != b) return LCA[0][a];
    return a;
}
int Sum[2][200005];

pii DFS3(int id){
    pii R = {Sum[0][id], Sum[1][id]};
    for (auto x : E3[id]) R += DFS3(x);
    if (R.x && R.y) NO();
    return R;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    REP(m,i){
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        E[a].pb(b), E[b].pb(a), UF1.join(a, b);
    }
    REP(n,i) if (!bio[i]) DFS(i);
    REP(n,i) for (auto x : E[i]){
        int a = UF2.un(i), b = UF2.un(x);
        if (a != b) E2[a].pb(b);
    } memset(bio, 0, sizeof bio), memset(dep, 0, sizeof dep);
    for (auto &x : E) x.clear();
    REP(n,i) if (!bio[UF2.un(i)]) DFS2(UF2.un(i), UF2.un(i));
    for (auto &x : E2) x.clear();
    FOR(1,20,i) REP(n,j) LCA[i][j] = LCA[i - 1][LCA[i - 1][j]];

    REP(q,i){
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        a = UF2.un(a), b = UF2.un(b);
        if (UF1.un(a) != UF1.un(b)) NO();
        ++Sum[0][a], ++Sum[1][b];
        int L = lca(a, b);
        --Sum[0][L], --Sum[1][L];
    }
    REP(n,i) if (UF2.un(i) == i && LCA[0][i] == i) DFS3(i);
    printf("Yes\n");

    return 0;
}