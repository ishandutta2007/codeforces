#include <cstdio>
#include <algorithm>

using namespace std;

int a[5][5];

int main()
{
    int n, ans = 1e9, i, j, k, l;
    char s[3];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%s", s);
        
        if (s[0] == 'R') {
            x = 0;
        } else if (s[0] == 'G') {
            x = 1;
        } else if (s[0] == 'B') {
            x = 2;
        } else if (s[0] == 'Y') {
            x = 3;
        } else {
            x = 4;
        }
        
        y = s[1] - '1';
        
        a[x][y]++;
    }
    
    for (i = 0; i < (1 << 5); i++) {
        for (j = 0; j < (1 << 5); j++) {
            int f = 0;
            
            for (k = 0; k < 5; k++) {
                int c = 0;
                
                for (l = 0; l < 5; l++) {
                    if ((i >> k) & 1) {
                        if ((j >> l) & 1) {
                            continue;
                        } else {
                            if (a[k][l] > 0) c++;
                        }
                    }
                }
                
                if (c >= 2) f += 2;
            }
            
            for (k = 0; k < 5; k++) {
                int c = 0;
                
                for (l = 0; l < 5; l++) {
                    if ((j >> k) & 1) {
                        if ((i >> l) & 1) {
                            continue;
                        } else {
                            if (a[l][k] > 0) c++;
                        }
                    }
                }
                
                if (c >= 2) f += 2;
            }
            
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    if ((i >> k) & 1) continue;
                    if ((j >> l) & 1) continue;
                    
                    if (a[k][l] > 0) f++;
                }
            }
            
            if (f <= 1) ans = min(ans, __builtin_popcount(i) + __builtin_popcount(j));
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}