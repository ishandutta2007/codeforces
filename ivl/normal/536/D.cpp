#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <cstring>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double
#define prr pair < real, real >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int oo = 1000000000;
const ll ool = (ll)oo * oo;

int n, m;
int s, t;
ll p[2005];
vector < pair < int, ll > > E[2005];

vector < ll > Dx, Dy;
vector < int > X, Y;

void Sazmi(vector < ll > &a, vector < int > &b){
    vector < ll > c = a;
    sort(c.begin(), c.end());
    int tt = (int)(unique(c.begin(), c.end()) - c.begin());
    REP(c.size() - tt, i) c.pop_back();
    for (auto x : a) b.pb((int)(lower_bound(c.begin(), c.end(), x) - c.begin() + 1));
}

vector < ll > Dijkstra(int id){
    vector < ll > R(n, ool);
    R[id] = 0;
    set < pair < ll, int > > S;
    S.insert({0, id});
    while (!S.empty()){
        id = S.begin()->y;
        S.erase(S.begin());
        for (auto x : E[id]){
            ll nd = R[id] + x.y;
            if (nd >= R[x.x]) continue;
            S.erase({R[x.x], x.x});
            R[x.x] = nd;
            S.insert({R[x.x], x.x});
        }
    } return R;
}

int ExM[2005][2005];
ll VM[2005][2005];

ll Max[2005][2005], Min[2005][2005];
int Pa[2005][2005], Pb[2005][2005];
ll Alfa[2005][2005], Beta[2005][2005];

int main(){
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t), --s, --t;
    REP(n,i) scanf("%I64d", p+i);
    REP(m,i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c), --a, --b;
        E[a].pb({b, c});
        E[b].pb({a, c});
    }
    Dx = Dijkstra(s), Dy = Dijkstra(t);
    Sazmi(Dx, X), Sazmi(Dy, Y);
    REP(n,i) X[i] = 2001 - X[i], Y[i] = 2001 - Y[i];
    REP(n,i) ++ExM[X[i]][Y[i]], VM[X[i]][Y[i]] += p[i];
    REP(2004,i) REP(2004,j) ExM[i+1][j+1] += ExM[i+1][j] + ExM[i][j+1] - ExM[i][j], VM[i+1][j+1] += VM[i+1][j] + VM[i][j+1] - VM[i][j];

    FOR(1,2005,x) FOR(1,2005,y){
        if (!ExM[x][y]) continue;
        int Start;
        // Alfa
        if (ExM[x][y] == ExM[x-1][y]) Start = Pa[x-1][y];
        else Start = x-1;
        Pa[x][y] = Start;
        Alfa[x][y] = 2 * VM[x][y] + Max[Start][y];
        Min[x][y] = min(Min[x][y-1], Alfa[x][y]);
        // ~Alfa
        // Beta
        if (ExM[x][y] == ExM[x][y-1]) Start = Pb[x][y-1];
        else Start = y-1;
        Pb[x][y] = Start;
        Beta[x][y] = -2 * VM[x][y] + Min[x][Start];
        Max[x][y] = max(Max[x-1][y], Beta[x][y]);
        // ~Beta
    }
    ll A = Alfa[2004][2004] - VM[2004][2004];
    if (A > 0) printf("Break a heart\n");
    if (A == 0) printf("Flowers\n");
    if (A < 0) printf("Cry\n");
    /*while (true){
        int x, y;
        scanf("%d%d", &x, &y);
        TRACE(Alfa[x][y] _ Beta[x][y]);
    }*/
    return 0;
}