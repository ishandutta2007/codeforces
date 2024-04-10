#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

using namespace std;

const int ALL = (1 << 24) - 1;

int n;
int Count[1 << 24];

int main(){
    scanf("%d", &n);
    REP(n){
        int x = ALL;
        char in[5];
        scanf("%s", in);
        x &= ~(1 << (in[0] - 'a'));
        x &= ~(1 << (in[1] - 'a'));
        x &= ~(1 << (in[2] - 'a'));
        ++Count[x];
    }
    for (int i = (1 << 23); i; i /= 2)
        FOR(0, 1 << 24, j)
            if (i & j)
                Count[i ^ j] += Count[j];
    int R = 0;
    FOR(0, 1 << 24, i)
        Count[i] = n - Count[i], R ^= (Count[i] * Count[i]);
    printf("%d\n", R);
    return 0;
}