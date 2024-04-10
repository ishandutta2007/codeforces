#include <cstdio>
#include <algorithm>
using namespace std;

double cnx[301];   // C(n, x)
double dmk[90001]; // C(m-x, k-x) / C(m, k)

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    cnx[0] = 1;
    for(int i = 1; i <= n; i++)
        cnx[i] = cnx[i - 1] * ((double) (n - i + 1) / i);
    dmk[0] = 1;
    for(int i = 1; i <= min(n * n, k); i++)
        dmk[i] = dmk[i - 1] * ((double) (k - i + 1) / (m - i + 1));
    double sum = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            int c = n * (i + j) - i * j;
            if(c <= k)
                sum += dmk[c] * cnx[i] * cnx[j];
        }
    }
    if(sum > 1e99)
        sum = 1e99;
    printf("%.11g\n", sum);
}

int main(){
#if 0
    while(true) solve();
#else
    solve();
#endif
}