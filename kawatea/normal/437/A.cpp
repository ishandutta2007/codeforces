#include <cstdio>
#include <cstring>

using namespace std;

char s[101];

int main()
{
    int f = 0, i, j;
    int a[4];
    
    for (i = 0; i < 4; i++) {
        scanf("%s", s);
        
        a[i] = strlen(s) - 2;
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) continue;
            
            if (a[i] < a[j] * 2) break;
        }
        
        if (j == 4) f |= 1 << i;
        
        for (j = 0; j < 4; j++) {
            if (i == j) continue;
            
            if (a[i] * 2 > a[j]) break;
        }
        
        if (j == 4) f |= 1 << i;
    }
    
    if (__builtin_popcount(f) == 1) {
        for (i = 0; i < 4; i++) {
            if ((f >> i) & 1) printf("%c\n", 'A' + i);
        }
    } else {
        puts("C");
    }
    
    return 0;
}