#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

struct Mat {
    int v[2][2];
    Mat() {memset(v, 0, sizeof(v));}
    Mat operator * (const Mat& c) const {
        Mat ans;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ans.v[i][j] += 1LL * v[i][k] * c.v[k][j] % MOD;
                    if (ans.v[i][j] >= MOD) ans.v[i][j] -= MOD;
                }
            }
        }
        return ans;
    }
};

Mat pow_mod(Mat A, long long k) {
    Mat ans;
    for (int i = 0; i < 2; i++) ans.v[i][i] = 1;
    while (k) {
        if (k&1) ans = ans * A;
        A = A * A;
        k >>= 1;
    }
    return ans;
}

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int main() {
    int k; long long a;
    Mat A; A.v[0][0] = MOD - 1; A.v[0][1] = 1;A.v[1][1] = 2;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &a);
        A = pow_mod(A, a);
    }
    //printf("%d %d\n", A.v[0][1], A.v[1][1]);
    int x = ((-2LL * A.v[0][1] % MOD + MOD) % MOD + A.v[1][1]) % MOD * pow_mod(2, MOD - 2) % MOD;
    int y = 1LL * A.v[1][1] * pow_mod(2, MOD - 2) % MOD;
    printf("%d/%d\n", x, y);
    return 0;
}