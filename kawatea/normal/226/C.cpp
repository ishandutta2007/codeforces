#include <iostream>
#include <algorithm>

using namespace std;

void mul(long long a[2][2], long long b[2][2], long long m)
{
    int i, j, k;
    long long c[2][2];
    
    c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % m) % m;
            }
        }
    }
    
    a[0][0] = c[0][0];
    a[0][1] = c[0][1];
    a[1][0] = c[1][0];
    a[1][1] = c[1][1];
}

void pow(long long a[2][2], long long n, long long m)
{
    long long b[2][2];
    
    b[0][0] = b[1][1] = 1;
    b[0][1] = b[1][0] = 0;
    
    while (n) {
        if (n % 2 == 1) mul(b, a, m);
        
        mul(a, a, m);
        
        n /= 2;
    }
    
    a[0][0] = b[0][0];
    a[0][1] = b[0][1];
    a[1][0] = b[1][0];
    a[1][1] = b[1][1];
}

int main()
{
    long long m, l, r, k, ans = 1, i;
    long long a[2][2];
    
    cin >> m >> l >> r >> k;
    
    for (i = k; ;i++) {
        long long x = r / i;
        long long y = r / x;
        long long z = (l - 1) / x;
        
        if (x <= 1000000) break;
        
        if (y - z >= k) ans = max(ans, x);
    }
    
    for (i = 1; i <= 1000000; i++) {
        long long x = r / i;
        long long y = (l - 1) / i;
        
        if (x - y >= k) ans = max(ans, i);
    }
    
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    
    pow(a, ans, m);
    
    cout << a[1][0] << endl;
    
    return 0;
}