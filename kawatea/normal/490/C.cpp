#include <cstdio>
#include <cstring>

using namespace std;

char s[1000001];
int c[1000001];

int main()
{
    int n, a, b, x = 0, y = 1, i, j;
    
    scanf("%s", s);
    scanf("%d %d", &a, &b);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        x = (x * 10 + s[i] - '0') % a;
        
        if (x == 0) c[i] = 1;
    }
    
    x = 0;
    
    for (i = n - 1; i > 0; i--) {
        x = (x + y * (s[i] - '0')) % b;
        y = y * 10 % b;
        
        if (s[i] != '0' && x == 0 && c[i - 1] == 1) {
            puts("YES");
            
            for (j = 0; j < i; j++) putchar(s[j]);
            puts("");
            for (; j < n; j++) putchar(s[j]);
            puts("");
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}