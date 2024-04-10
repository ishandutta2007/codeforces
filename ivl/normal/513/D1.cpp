#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void imp(){printf("IMPOSSIBLE\n"); exit(0);}

int n, c;
char in[105];
vector < int > l[105], r[105];
int par[105];
int taken[105];

bool bio[105][105];
bool memo[105][105];
bool good(int lo, int hi){
     if (lo > hi) return true;
     if (bio[lo][hi]++) return memo[lo][hi];
     for (int g1 = lo; g1 <= hi; ++g1){
         if (!good(lo + 1, g1) || !good(g1 + 1, hi)) continue;
         if (l[lo].size() && l[lo].back() > g1) continue;
         if (r[lo].size() && r[lo].back() > hi) continue;
         if (r[lo].size() && r[lo][0] < g1 + 1) continue;
         return memo[lo][hi] = true;
     }
     return memo[lo][hi] = false;
}
void rek(int lo, int hi){
     if (lo > hi) return;
     //if (bio[lo][hi]++) return memo[lo][hi];
     for (int g1 = lo; g1 <= n; ++g1){
         if (!good(lo + 1, g1) || !good(g1 + 1, hi)) continue;
         if (l[lo].size() && l[lo].back() > g1) continue;
         if (r[lo].size() && r[lo].back() > hi) continue;
         if (r[lo].size() && r[lo][0] < g1 + 1) continue;
         //return memo[lo][hi] = true;
         rek(lo + 1, g1);
         printf("%d ", lo);
         rek(g1 + 1, hi);
         return;
     }
     //return memo[lo][hi] = false;
}

int main(){
    scanf("%d%d", &n, &c);
    for (int i = 0; i < c; ++i){
        int a, b;
        scanf("%d%d%s", &a, &b, in);
        if (a >= b) imp();
        if (in[0] == 'L') l[a].push_back(b); else r[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) sort(l[i].begin(), l[i].end()), sort(r[i].begin(), r[i].end());
    /*for (int i = 1; i <= n; ++i) taken[i] = -1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < l[i].size(); ++j) taken[l[i][j]] = max(taken[l[i][j]], i);
        for (int j = 0; j < r[i].size(); ++j) taken[r[i][j]] = max(taken[r[i][j]], i);
    }*/
    if (!good(1, n)) imp();
    rek(1, n); printf("\n");
    return 0;
}