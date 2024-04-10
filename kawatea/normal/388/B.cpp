#include <cstdio>
#include <algorithm>

using namespace std;

int a[92][92];

int main()
{
    int k, n = 92, i, j, l;
    
    scanf("%d", &k);
    
    for (i = 0; i < 29; i++) {
        int x = i * 3 + 2;
        
        a[x][x + 3] = a[x + 3][x] = 1;
        
        for (j = 1; j < 3; j++) {
            for (l = 4; l < 6; l++) {
                a[x + j][x + l] = a[x + l][x + j] = 1;
            }
        }
    }
    
    for (i = 0; i < 30; i++) {
        if ((k >> i) & 1) a[(29 - i) * 3 + 2][(29 - i) * 3 + 3] = a[(29 - i) * 3 + 3][(29 - i) * 3 + 2] = 1;
    }
    
    a[0][2] = a[2][0] = 1;
    a[1][90] = a[90][1] = a[1][91] = a[91][1] = 1;
    
    printf("%d\n", n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                putchar('Y');
            } else {
                putchar('N');
            }
        }
        
        puts("");
    }
    
    return 0;
}