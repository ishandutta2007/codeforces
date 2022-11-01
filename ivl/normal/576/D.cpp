#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
vector < pair < int, pii > > E;

bitset < 155 > Con[155][31];

int main(){
    scanf("%d%d", &n, &m);
    E.resize(m);
    REP(m,i) scanf("%d%d%d", &E[i].y.x, &E[i].y.y, &E[i].x), --E[i].y.x, --E[i].y.y;
    E.pb({2e9, {n-1, n-1}});
    E.pb({0, {n-1, n-1}});
    sort(E.begin(), E.end());

    bitset < 155 > V;
    V[0] = 1;
    int Dis = 0;

    for (auto x : E){
        int t = x.x - Dis;
        bitset < 155 > V2 = V;
        REP(31,i) if ((t>>i)&1){
            bitset < 155 > V3;
            REP(n,j) if (V2[j]) V3 |= Con[j][i];
            V2 = V3;
        }
        if (V2[n-1] == false){
            V = V2;
            Dis = x.x;
            Con[x.y.x][0][x.y.y] = true;
            REP(30,i) REP(n,j) REP(n,k) if (Con[j][i][k]) Con[j][i+1] |= Con[k][i];
            continue;
        }
        for (int i = 30; i >= 0; --i){
            V2 = V;
            REP(n,j) if (V[j]) V2 |= Con[j][i];
            if (V2[n-1] == 0) V = V2, Dis += (1<<i);
        } printf("%d\n", Dis + !V[n-1]);
        return 0;
    } printf("Impossible\n");
    return 0;
}