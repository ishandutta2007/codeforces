#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, q;

vector < int > Out[50005];
int Count[50005];
bool Online[50005];

void FlipState(int x){
    int T = (Online[x] ? -1 : 1);
    Online[x] = !Online[x];
    for (auto y : Out[x])
        Count[y] += T;
}
int GetNum(int x){
    int R = Count[x];
    for (auto y : Out[x])
        if (Online[y])
            ++R;
    return R;
}
void AddEdge(int a, int b){
    if (Out[a].size() > Out[b].size()) swap(a, b);
    Out[a].pb(b);
    if (Online[a]) ++Count[b];
}
void DelEdge(int a, int b){
    FOR(0, Out[a].size(), i)
        if (Out[a][i] == b){
            Out[a].erase(Out[a].begin() + i);
            if (Online[a]) --Count[b];
        }
    swap(a, b);
    FOR(0, Out[a].size(), i)
        if (Out[a][i] == b){
            Out[a].erase(Out[a].begin() + i);
            if (Online[a]) --Count[b];
        }
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    int o; scanf("%d", &o);
    REP(o){
        int x;
        scanf("%d", &x);
        FlipState(x);
    }
    REP(m){
        int a, b;
        scanf("%d%d", &a, &b);
        AddEdge(a, b);
    }
    REP(q){
        char c[5];
        scanf("%s", c);
        int u;
        scanf("%d", &u);
        if (*c == 'O' || *c == 'F') FlipState(u);
        else if (*c == 'C') printf("%d\n", GetNum(u));
        else {
            int v;
            scanf("%d", &v);
            if (*c == 'A') AddEdge(u, v);
            else DelEdge(u, v);
        }
    }
    return 0;
}