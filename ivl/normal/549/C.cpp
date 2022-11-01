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

int n, k;
int a, b;
int l;

void prvi(){
    printf("Stannis\n");
    exit(0);
}

void drugi(){
    printf("Daenerys\n");
    exit(0);
}

int main(){
    scanf("%d%d", &n, &k);
    REP(n){
        int x;
        scanf("%d", &x);
        if (x & 1) ++a; else ++b;
    }
    
    if (n == k){
        if (a & 1) prvi(); else drugi();
    }
    l = n - k;
    int t = l / 2, tt = l - t;
    if (a >= l && b >= l){
        if (t == tt) drugi(); else prvi();
    }
    if (a <= t) drugi();
    if (b <= t){
        if ((a + b - l) & 1) prvi(); else drugi();
    }
    if (tt != t) prvi();
    drugi();
    return 0;
}