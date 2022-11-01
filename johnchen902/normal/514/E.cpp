#include <cstdio>
using namespace std;

constexpr int mod = 1000000007;

struct Matrix {
    int a[101][101];
};

void multiply(const Matrix& lhs, const Matrix& rhs, Matrix& result) {
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++) {
            result.a[i][j] = 0;
            for(int k = 0; k < 101; k++)
                result.a[i][j] = (result.a[i][j] + lhs.a[i][k] * 1LL * rhs.a[k][j]) % mod;
        }
}

void pow(const Matrix& x, int a, Matrix& result) {
    if(a == 0) {
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                result.a[i][j] = i == j;
    } else {
        Matrix tmp;
        pow(x, a / 2, tmp);
        if(a % 2 == 0) {
            multiply(tmp, tmp, result);
        } else {
            Matrix tmp2;
            multiply(tmp, tmp, tmp2);
            multiply(x, tmp2, result);
        }
    }
}

int c[101];
int dp[101];
Matrix mx;
Matrix xx;

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        c[d]++;
    }
    dp[0] = 1;
    for(int i = 1; i < 101; i++) {
        dp[i] = 1;
        for(int j = 1; j <= i; j++)
            dp[i] = (dp[i] + dp[i - j] * 1LL * c[j]) % mod;
    }
//    printf("> %d\n", dp[100]);
    mx.a[0][0] = 1;
    for(int i = 1; i + 1 <= 100; i++)
        mx.a[i][i + 1] = 1;
    mx.a[100][0] = 1;
    for(int i = 1; i <= 100; i++)
        mx.a[100][i] = c[101 - i];
    pow(mx, x, xx);
    int result = xx.a[1][0];
    for(int i = 1; i <= 100; i++)
        result = (result + xx.a[1][i] * 1LL * dp[i - 1]) % mod;
    printf("%d\n", result);
}