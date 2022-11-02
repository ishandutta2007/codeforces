#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[400];

int main()
{
    int k, ans = 0, n, i, j, l;
    
    scanf("%s", s);
    scanf("%d", &k);
    
    n = strlen(s);
    
    for (i = 0; i < k; i++) s[n + i] = '.';
    
    for (i = 0; i < n + k; i++) {
        for (j = 2; i + j <= n + k; j += 2) {
            for (l = 0; l < j / 2; l++) {
                if (s[i + l] == '.') continue;
                if (s[i + j / 2 + l] == '.') continue;
                
                if (s[i + l] != s[i + j / 2 + l]) break;
            }
            
            if (l == j / 2) ans = max(ans, j);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}