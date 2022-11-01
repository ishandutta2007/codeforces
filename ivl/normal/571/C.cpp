#include <bits/stdc++.h>

#define ll long long
#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

pii operator+(pii a, pii b){return {a.x + b.x, a.y + b.y};}
void operator+=(pii &a, pii b){a.x += b.x, a.y += b.y;}

void imp(){printf("NO\n"); exit(0);}

int n, m;
vector < int > Cl[200005];

bool Solved[200005];
bool Out[200005];
bool Done[200005];

int Usage[2][200005];
vector < int > Used[200005];

void Finish(int id);
void FinVal(int id);

void Finish(int id){
    if (Done[id]++) return;
    for (auto x : Cl[id]){
        if (x > 0) --Usage[1][x];
        else --Usage[0][-x];
        FinVal(abs(x));
    }
}

void FinVal(int id){
    if (Usage[0][id] && Usage[1][id]) return;
    if (Solved[id]++) return;
    Out[id] = Usage[1][id];
    for (auto x : Used[id]) Finish(abs(x));
}

set < pii > E[200005];

pii DfsCount(int id){
    static bool bio[200005];
    if (bio[id]++) return {0, 0};
    pii R = {1, 0};
    for (auto x : E[id]) R += DfsCount(x.x) + (pii){0, 1};
    return R;
}

set < pair < int, int > > S;

void Erase(int a, int b, int id){
    S.erase({E[a].size(), a});
    S.erase({E[-b].size(), -b});

    E[a].erase({-b, id});
    E[-b].erase({a, -id});

    S.insert({E[a].size(), a});
    S.insert({E[-b].size(), -b});
}

void Set(int id);
void Spread(int id);

void Set(int id){
    int t = abs(id);
    if (Solved[t]++) assert(0);
    Out[t] = (id > 0);
    if (id > 0){
        int a = Used[t][0], b = Used[t][1];
        if (a < 0) swap(a, b);
        Done[a] = true;
        Erase(a, b, t);
        Spread(a);
    } else {
        int a = Used[t][0], b = Used[t][1];
        if (a > 0) swap(a, b);
        Done[-a] = true;
        Erase(b, a, t);
        Spread(-a);
    }
}

void Spread(int id){
    while (!E[id].empty()) Set(-E[id].begin()->y);
}

void SolveClass(int id){
    if (!E[id].empty()) Set(E[id].begin()->y);
    while (!E[id].empty()) Set(-E[id].begin()->y);
}

int main(){
    scanf("%d%d", &n, &m);
    FOR(1,n+1,i){
        int k;
        scanf("%d", &k);
        if (k == 0) imp();
        REP(k,j){
            int t;
            scanf("%d", &t);
            Cl[i].pb(t);
            if (t > 0) ++Usage[1][t], Used[t].pb(i);
            else ++Usage[0][-t], Used[-t].pb(-i);
        }
    }
    FOR(1,m+1,i) FinVal(i);

    FOR(1,m+1,i) if (!Solved[i]){
        int a = Used[i][0], b = Used[i][1];
        if (a < 0) swap(a, b);
        E[a].insert({-b, i});
        E[-b].insert({a, -i});
    }
    FOR(1,n+1,i) if (!Done[i]){
        pii t = DfsCount(i);
        if (t.x * 2 - 2 == t.y) imp(); // stablo
    }

    FOR(1,n+1,i) if (!Done[i]) S.insert({E[i].size(), i});
    while (!S.empty()){
        int id = S.begin()->y;
        SolveClass(id);
        S.erase({E[id].size(), id});
    }
    FOR(1,n+1,i){
        bool ch = false;
        for (auto x : Cl[i]){
            if (x > 0) ch |= Out[x];
            else ch |= !Out[-x];
        }
        if (!ch) imp();
    }
    printf("YES\n");
    FOR(1,m+1,i) printf("%d", (int)Out[i]); printf("\n");
    return 0;
}