#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int n, b, k, x;

struct mat {
    int v[100][100];
    mat() {memset(v, 0, sizeof(v));}

    mat operator * (const mat& c) const {
        mat ans;
        for (int k = 0; k < x; k++) {
            for (int i = 0; i < x; i++) {
                if (v[i][k] == 0) continue;
                for (int j = 0; j < x; j++) {
                    ans.v[i][j] = (ans.v[i][j] + 1LL * v[i][k] * c.v[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }
};

int cnt[10];

mat pow_mod(mat A, int k) {
    mat ans;
    for (int i = 0; i < x; i++) ans.v[i][i] = 1;
    while (k) {
        if (k&1) ans = ans * A;
        A = A * A;
        k >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d", &n, &b, &k, &x);
    while (n--) {
        int xx;
        scanf("%d", &xx);
        cnt[xx]++;
    }
    mat A;
    for (int i = 0; i < x; i++) {
        for (int j = 1; j < 10; j++) {
            A.v[i][(i * 10 + j) % x] += cnt[j];
        }
    }
    A = pow_mod(A, b);
    printf("%d\n", A.v[0][k]);
    return 0;
}