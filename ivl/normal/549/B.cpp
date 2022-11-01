#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define pb push_back

using namespace std;

int n;
char in[105][105];
int a[105];

vector < int > out;
bool used[105];
int cnt[105];

int main(){
    scanf("%d", &n);
    FOR(0, n, i) scanf("%s", in[i]);
    FOR(0, n, i) scanf("%d", a + i);
    REP(n) FOR(0, n, i) if (a[i] == cnt[i]){
        FOR(0, n, j) if (in[i][j] == '1') ++cnt[j];
        out.pb(i);
    }
    printf("%d\n", out.size());
    for (auto x : out) printf("%d\n", x + 1);
    return 0;
}