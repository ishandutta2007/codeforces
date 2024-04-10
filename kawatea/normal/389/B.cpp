#include <cstdio>

using namespace std;

char s[100][101];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s[i][j] == '.') continue;
            
            if (i + 2 >= n || j - 1 < 0 || j + 1 >= n || s[i + 1][j - 1] == '.' || s[i + 1][j] == '.' || s[i + 1][j + 1] == '.' || s[i + 2][j] == '.') {
                puts("NO");
                
                return 0;
            }
            
            s[i + 1][j - 1] = s[i + 1][j] = s[i + 1][j + 1] = s[i + 2][j] = '.';
        }
    }
    
    puts("YES");
    
    return 0;
}