#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void Imp(){printf("NO\n"); exit(0);}

int gcd(int a, int b){
    while (b) a %= b, swap(a, b);
    return a;
}

int n;
int p[100005];

vector < vector < int > > Cyc;
bool Bio[100005];
int Loc[100005];
int Pos[100005];

void GenCyc(int id){
    Loc[id] = (int)Cyc.size();
    Cyc.pb({});
    int x = id;
    do {
        Bio[x] = true;
        Loc[x] = Loc[id];
        Pos[x] = (int)Cyc.back().size();
        Cyc.back().pb(x);
        x = p[x];
    } while (x != id);
}

vector < int > Sz[100005];
int Cnt[100005];
int Edge[100005];
vector < int > Inv[100005];

void Join(int a, int b){
    if (Cyc[a].size() < Cyc[b].size()) swap(a, b);
    int x = (int)Cyc[b].size();
    REP(Cyc[a].size(),i) printf("%d %d\n", Cyc[a][i]+1, Cyc[b][i%x]+1);
}

void DFS(int id){
    REP(Sz[id].size()-1, i) Join(Sz[id][i], Sz[id][i+1]);
    REP(Inv[id].size(), i) Join(Sz[id][0], Sz[Inv[id][i]].front());
}

int main(){
    scanf("%d", &n);
    REP(n,i) scanf("%d", p+i), --p[i];
    REP(n,i) if (!Bio[i]) GenCyc(i);
    int GCD = 0;
    for (auto &x : Cyc) GCD = gcd(GCD, (int)x.size());
    if (GCD > 2) Imp();

    REP(Cyc.size(),i) Sz[Cyc[i].size()].pb(i);
    REP(n+1,i) Cnt[i] = (int)Sz[i].size();
    int Root;
    REP(n+1,i) if (Cnt[i]){Root = i; break;}
    FOR(Root+1,n+1,i) if (Cnt[i]){
        if (i%Root != 0) Imp();
        Inv[Root].pb(i);
    }

    printf("YES\n");
    REP(n+1,i) if (Sz[i].size()) DFS(i);

    if (GCD == 2){
        int id = -1;
        for (int i = 2; i <= n; i += 4) if (Sz[i].size()){id = Sz[i].front(); break;}
        int sz = (int)Cyc[id].size();
        REP(sz/2, i) printf("%d %d\n", Cyc[id][i]+1, Cyc[id][i+sz/2]+1);
    }

    return 0;
}