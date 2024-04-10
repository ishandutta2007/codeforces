#include <cstdio>

using namespace std;

int a[26][26];
char s[200001];
char t[200001];

int main()
{
    int n, ans = 0, i, j, k;
    
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    
    for (i = 0; i < n; i++) {
        if (s[i] != t[i]) ans++;
        
        a[s[i] - 'a'][t[i] - 'a'] = i + 1;
    }
    
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (i == j) continue;
            
            if (a[i][j] > 0 && a[j][i] > 0) {
                printf("%d\n", ans - 2);
                printf("%d %d\n", a[i][j], a[j][i]);
                
                return 0;
            }
        }
    }
    
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (i == j) continue;
            
            for (k = 0; k < 26; k++) {
                if (j == k) continue;
                
                if (a[i][j] > 0 && a[j][k] > 0) {
                    printf("%d\n", ans - 1);
                    printf("%d %d\n", a[i][j], a[j][k]);
                    
                    return 0;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    printf("%d %d\n", -1, -1);
    
    return 0;
}