#include <cstdio>
using namespace std;
struct Mx {
    int m[100][100];
    int *operator [] (int x) { return m[x]; }
    const int *operator [] (int x) const { return m[x]; }
};
Mx operator * (const Mx &lhs, const Mx &rhs) {
    Mx m = {};
    for(int i = 0; i < 100; i++)
        for(int k = 0; k < 100; k++)
            for(int j = 0; j < 100; j++)
                m[i][j] = (m[i][j] +
                        (long long) lhs[i][k] * rhs[k][j]) %
                        1000000007;
    return m;
}
Mx pow(Mx m, int n) {
    if(n == 1)
        return m;
    Mx mm = pow(m, n / 2);
    if(n % 2)
        return mm * mm * m;
    else
        return mm * mm;
}
int main() {
    int n, b, k, x;
    scanf("%d %d %d %d", &n, &b, &k, &x);
    int ca[9] = {};
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        ca[a - 1]++;
    }
    Mx m1 = {};
    for(int j = 0; j < x; j++)
        for(int i = 0; i < 9; i++)
            m1[j][(j + i + 1) % x] += ca[i];
    Mx m2 = {};
    for(int j = 0; j < x; j++)
        m2[j][(j * 10) % x]++;
    Mx mm = m1;
    if(b - 1 > 0)
        mm = mm * pow(m2 * m1, b - 1);
    printf("%d\n", mm[0][k]);
}