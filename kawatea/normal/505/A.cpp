#include <cstdio>
#include <cstring>

using namespace std;

char s[11];
char t[12];

int main()
{
    int n, i, j, k;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j < 26; j++) {
            for (k = 0; k < i; k++) t[k] = s[k];
            
            t[k++] = 'a' + j;
            
            for (; k <= n; k++) t[k] = s[k - 1];
            
            for (k = 0; k <= n; k++) {
                if (t[k] != t[n - k]) break;
            }
            
            if (k == n + 1) {
                printf("%s\n", t);
                
                return 0;
            }
        }
    }
    
    puts("NA");
    
    return 0;
}