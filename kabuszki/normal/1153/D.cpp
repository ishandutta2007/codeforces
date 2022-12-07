#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

const int N = 300005;

VI v[N];
int mm[N], sz[N], wyn[N];

int solve(int co, VII& w) {
    if (co == 1) {
        int tot_sz = 0;
        for (auto p : w) tot_sz += p.ND;
        int mind = tot_sz;
        for (auto p : w) mind = min(mind, p.ND - p.ST);
        return tot_sz - mind;
    } else {
        int dupsko = 0;
        for (auto p : w) dupsko += (p.ST - 1);
        return dupsko + 1;
    }
    return -1;
}

void dfs(int a) {
    if (v[a].empty()) {
        sz[a] = 1;
        wyn[a] = 1;
        return;
    }
    VII x;
    for (int b : v[a]) {
        dfs(b);
        sz[a] += sz[b];
        x.EB(wyn[b], sz[b]);
    }
    wyn[a] = solve(mm[a], x);
}

void jebaj() {
    int n;
    cin >> n;
    REP(i, n) {
        cin >> mm[i];
    }
    FOR(i, 1, n - 1) {
        int a;
        cin >> a;
        a--;
        v[a].PB(i);
    }
    dfs(0);
    cout << wyn[0] << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}