#include <cstdio>

using namespace std;

long long a[51][5];

int main()
{
    int k, x, n, m, i, j, x1, y1, x2, y2;
    
    scanf("%d %d %d %d", &k, &x, &n, &m);
    
    a[1][0] = 1;
    a[2][1] = 1;
    
    for (i = 3; i <= k; i++) {
        for (j = 0; j <= 4; j++) a[i][j] = a[i - 2][j] + a[i - 1][j];
        
        if (i % 2 == 0) {
            a[i][3]++;
        } else {
            if (i == 3) {
                a[i][2]++;
            } else {
                a[i][4]++;
            }
        }
    }
    
    for (i = 0; i <= n / 2; i++) {
        for (j = 0; j <= m / 2; j++) {
            for (x1 = 0; x1 < 2; x1++) {
                for (y1 = 0; y1 < 2; y1++) {
                    for (x2 = 0; x2 < 2; x2++) {
                        for (y2 = 0; y2 < 2; y2++) {
                            int p = i * 2 + x1 + y1;
                            int q = j * 2 + x2 + y2;
                            
                            if (p > n || q > m) continue;
                            
                            if (a[k][0] * i + a[k][1] * j + a[k][2] * x2 * y1 + a[k][3] * x1 * y2 + a[k][4] * x2 * y2 == x) {
                                int l;
                                char s1[101];
                                char s2[101];
                                
                                l = 0;
                                
                                if (x1) s1[l++] = 'C';
                                
                                while (i) {
                                    s1[l++] = 'A';
                                    s1[l++] = 'C';
                                    
                                    i--;
                                }
                                
                                while (l < n - 1) s1[l++] = 'B';
                                
                                if (y1) {
                                    s1[l++] = 'A';
                                } else if (l < n) {
                                    s1[l++] = 'B';
                                }
                                
                                s1[l] = '\0';
                                
                                l = 0;
                                
                                if (x2) s2[l++] = 'C';
                                
                                while (j) {
                                    s2[l++] = 'A';
                                    s2[l++] = 'C';
                                    
                                    j--;
                                }
                                
                                while (l < m - 1) s2[l++] = 'B';
                                
                                if (y2) {
                                    s2[l++] = 'A';
                                } else if (l < m) {
                                    s2[l++] = 'B';
                                }
                                
                                s2[l] = '\0';
                                
                                printf("%s\n", s1);
                                printf("%s\n", s2);
                                
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    puts("Happy new year!");
    
    return 0;
}