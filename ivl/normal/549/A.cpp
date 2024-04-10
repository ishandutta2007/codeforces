#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define pb push_back

using namespace std;

int n, m;
char in[55][55];

bool mat[256];
bool check(int a, int b){
    memset(mat, 0, sizeof mat);
    FOR(0,2,i)FOR(0,2,j)mat[in[a+i][b+j]]++;
    for (auto x : (string)"face") if (!mat[x]){
        //if (a == 1 && b == 1) printf("%c", x); printf("%d %d\n", a, b);
        return false;
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    FOR(0, n, i) scanf("%s", in[i]);
    int r = 0;
    FOR(0, n - 1, i) FOR(0, m - 1, j) if (check(i, j)) ++r;
    printf("%d\n", r);
    return 0;
}