#include <cstdio>
#include <cstring>

using namespace std;

char c[11] = "CODEFORCES";
char s[101];

int main()
{
    int n, i, j;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (n < 10) {
        puts("NO");
        
        return 0;
    }
    
    for (i = 0; i <= 10; i++) {
        if (strncmp(s, c, i) != 0) continue;
        if (strncmp(s + n - 10 + i, c + i, 10 - i) != 0) continue;
        
        puts("YES");
        
        return 0;
    }
    
    puts("NO");
    
    return 0;
}