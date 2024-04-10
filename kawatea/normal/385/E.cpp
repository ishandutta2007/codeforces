#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

typedef vector<long long> array;
typedef vector<array> matrix;

matrix identify(int n)
{
    matrix a(n, array(n));
    
    for (int i = 0; i < n; i++) a[i][i] = 1;
    
    return a;
}

array mul(matrix &a, array &x)
{
    array y(a.size());
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            y[i] = (y[i] + a[i][j] * x[j] % n) % n;
        }
    }
    
    return y;
}

matrix mul(matrix &a, matrix &b)
{
    matrix c(a.size(), array(b[0].size()));
    
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c[i].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % n) % n;
            }
        }
    }
    
    return c;
}

matrix pow(matrix &a, long long n)
{
    matrix b = identify(a.size());
    
    while (n > 0) {
        if (n & 1) b = mul(b, a);
        a = mul(a, a);
        n >>= 1;
    }
    
    return b;
}

int main()
{
    int sx, sy, dx, dy, i;
    long long t;
    matrix a(6, array(6));
    array b(6);
    
    scanf("%d %d %d %d %d %I64d", &n, &sx, &sy, &dx, &dy, &t);
    
    a[0][0] = a[0][5] = a[1][1] = a[1][5] = a[2][5] = a[3][5] = 2;
    a[0][1] = a[0][2] = a[0][4] = a[1][0] = a[1][3] = a[1][4] = a[2][0] = a[2][1] = a[2][2] = a[2][4] = a[3][0] = a[3][1] = a[3][3] = a[3][4] = a[4][4] = a[4][5] = a[5][5] = 1;
    b[0] = sx - 1;
    b[1] = sy - 1;
    b[2] = (dx % n + n) % n;
    b[3] = (dy % n + n) % n;
    b[4] = 0;
    b[5] = 1;
    
    a = pow(a, t);
    
    b = mul(a, b);
    
    printf("%I64d %I64d\n", b[0] + 1, b[1] + 1);
    
    return 0;
}