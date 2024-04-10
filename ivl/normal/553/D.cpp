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

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

const double ep = 1e-12;

int n, m, k;
bool bad[100005];
vector < int > E[100005];
double t[100005], v[100005];

set < pair < double, int > > S;
bool dead[100005];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    REP(k,i){int t; scanf("%d", &t); bad[t - 1] = true;}
    REP(m,i){
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        E[a].pb(b), E[b].pb(a);
    }
    REP(n,i) t[i] = 1.0 / E[i].size(), v[i] = 1 - 2 * bad[i];
    REP(n,i) S.insert({v[i], i});
    double Opt = 0;
    while (!S.empty()){
        double d = S.begin()->x;
        int id = S.begin()->y;
        S.erase(S.begin()), dead[id] = true;
        Opt = max(Opt, d);
        for (auto x : E[id]) if (!dead[x]){
            S.erase({v[x], x});
            v[x] -= t[x];
            S.insert({v[x], x});
        }
    } memset(dead, 0, sizeof dead);
    REP(n,i) t[i] = 1.0 / E[i].size(), v[i] = 1 - 2 * bad[i];
    REP(n,i) S.insert({v[i], i});
    while (!S.empty()){
        double d = S.begin()->x;
        int id = S.begin()->y;
        if (d + ep > Opt) break;
        S.erase(S.begin()), dead[id] = true;
        Opt = max(Opt, d);
        for (auto x : E[id]) if (!dead[x]){
            S.erase({v[x], x});
            v[x] -= t[x];
            S.insert({v[x], x});
        }
    }
    printf("%d\n", S.size());
    for (auto x : S) printf("%d ", x.y + 1); printf("\n");
    return 0;
}