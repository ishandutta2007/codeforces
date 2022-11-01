#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int l = max(n, m);
    const long long MOD = int(1e9) + 7;
    vector< vector<long long> > ways(k+1, vector<long long>(l+1));
    ways[0].assign(l+1, 1);
    ways[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        long long psum = 0;
        for (int j = i*2 + 1; j <= l; j++) {
            psum += ways[i-1][j-2];
            if (psum >= MOD)
                psum -= MOD;
            ways[i][j] = ways[i][j-1] + psum;
            if (ways[i][j] >= MOD)
                ways[i][j] -= MOD;
        }
    }
    printf("%lld\n", ways[k][n] * ways[k][m] % MOD);
    return 0;
}