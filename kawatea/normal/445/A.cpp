#include <cstdio>

using namespace std;

char s[100][101];

int main()
{
    int n, m, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    s[i][j] = 'B';
                } else {
                    s[i][j] = 'W';
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) printf("%s\n", s[i]);
    
    return 0;
}