#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define pb push_back

using namespace std;

int n;
int in[200005];

vector < int > v;

int main(){
    scanf("%d", &n);
    FOR(0, n, i) scanf("%d", in + i), v.pb(in[i] + i);
    sort(v.begin(), v.end());
    if (unique(v.begin(), v.end()) != v.end()){printf(":(\n"); return 0;}
    FOR(0, n, i) printf("%d ", v[i] - i); printf("\n");
    return 0;
}