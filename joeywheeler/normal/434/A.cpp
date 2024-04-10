#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (long long i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long long n, m;
long long ccb[100005];
vector<long long> pos[100005];
vector<long long> g[100005];

vector<long long> v;

int main() {
    scanf("%I64d %I64d", &n, &m);
    for (long long i = 0; i < m; i++) {
        long long x;
        scanf("%I64d", &x);
        if (v.empty() || v.back() != x) v.push_back(x);
    }
    m = sz(v);
    long long tot = 0;
    for (long long i = 0; i < m-1; i++) tot += abs(v[i+1]-v[i]);
    for (long long i = 0; i < m; i++) {
        if (i+1 != m) {
            ccb[v[i]] += abs(v[i+1]-v[i]);
            g[v[i]].push_back((v[i+1]));
        }
        if (i != 0) {
            ccb[v[i]] += abs(v[i-1]-v[i]);
            g[v[i]].push_back((v[i-1]));
        }
        pos[v[i]].push_back(i);
    }
    long long bd = 0;
    FO(i,0,100005) if (!g[i].empty()) {
        sort(g[i].begin(),g[i].end());
        long long bi = g[i][g[i].size()/2];
        long long nv = 0;
        FO(j,0,sz(pos[i])) {
            nv += (pos[i][j] > 0 ? abs(bi-v[pos[i][j]-1]) : 0) + 
                (pos[i][j]+1 < m ? abs(bi-v[pos[i][j]+1]) : 0);
        }
        bd = min(bd, nv-ccb[i]);
    }
    printf("%I64d\n", tot+bd);
}