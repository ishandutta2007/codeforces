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
char in[105][105];

int inv[105][105];
int sol(){
    memset(inv, 0, sizeof inv);
    int r = 0;

    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j){
            inv[i][j] += inv[i + 1][j] + inv[i][j + 1] - inv[i + 1][j + 1];

            if (in[i][j] == 'W' && inv[i][j] != 1 || in[i][j] == 'B' && inv[i][j] != -1){
                ++r;
                inv[i][j] = (in[i][j] == 'W' ? 1 : -1);
            }
        }
    return r;
}

int main(){
    scanf("%d%d", &n, &m);
    FOR(0, n, i) scanf("%s", in[i]);
    int r = sol();
    printf("%d\n", r);
    return 0;
}