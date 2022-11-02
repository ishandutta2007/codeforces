#include <cstdio>

using namespace std;

int a[100];
int b[100];

void get(int a[], int n)
{
    int i;
    
    if (n == 1) {
        a[0] = 1;
    } else if (n == 2) {
        a[0] = 3;
        a[1] = 4;
    } else if (n % 2 == 0) {
        for (i = 0; i < n - 1; i++) a[i] = 1;
        a[n - 1] = n / 2 - 1;
    } else {
        for (i = 0; i < n - 2; i++) a[i] = 1;
        a[n - 2] = 2;
        a[n - 1] = n / 2 + 1;
    }
}

int main()
{
    int n, m, i, j;
    
    scanf("%d %d", &n, &m);
    
    get(a, n);
    get(b, m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (j > 0) putchar(' ');
            
            printf("%d", a[i] * b[j]);
        }
        
        puts("");
    }
    
    return 0;
}