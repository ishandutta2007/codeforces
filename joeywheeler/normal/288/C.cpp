#include <cstdio>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int cpl(int x, int n) {
    int r = (~x) & ((1<<n)-1);
    return r;
}

int nb(int x) {
    int r = 0;
    while (x) r++, x /= 2;
    return r;
}

int rs[1000005];

int main() {
    int n, N;
    scanf("%d", &n); N = n;

    while (n >= 0) {
        int s = nb(n);
        FO(i,cpl(n,s),n+1) rs[i] = cpl(i,s);
        n = cpl(n,s)-1;
    }
    n = N;

    long long m = 0;
    FO(i,0,n+1) m += i ^ rs[i];
    printf("%lld\n", m);
    FO(i,0,n+1) printf("%d ", rs[i]);
    printf("\n");
}