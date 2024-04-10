#include <stdio.h>
#include <string.h>

int main()
{
    int n1, n2, x = 0, y = 0, i;
    char s1[100];
    char s2[100];
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n1 = strlen(s1);
    n2 = strlen(s2);
    
    for (i = 0; i < n1; i++) {
        if (s1[i] == '|') break;
        
        x++;
    }
    
    for (i++; i < n1; i++) y++;
    
    if ((x + y + n2) % 2 == 1 || x + n2 < y || y + n2 < x) {
        puts("Impossible");
    } else {
        int z = (x + y + n2) / 2;
        
        for (i = 0; i < z - x; i++) putchar(s2[i]);
        
        for (i = 0; i < x; i++) putchar(s1[i]);
        
        putchar('|');
        
        for (i = x + 1; i < n1; i++) putchar(s1[i]);
        
        for (i = z - x; i < n2; i++) putchar(s2[i]);
        
        puts("");
    }
    
    return 0;
}