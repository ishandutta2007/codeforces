#include <stdio.h>
#include <string.h>

char s[101];
char t[101];
int a[26];
int b[26];

int main()
{
    int n1, n2, i, j;
    
    scanf("%s", s);
    scanf("%s", t);
    
    n1 = strlen(s);
    n2 = strlen(t);
    
    if (n1 > n2) {
        for (i = 0, j = 0; i < n1 && j < n2; ) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        if (j == n2) {
            puts("automaton");
            
            return 0;
        }
    }
    
    for (i = 0; i < n1; i++) a[s[i] - 'a']++;
    for (i = 0; i < n2; i++) b[t[i] - 'a']++;
    
    if (n1 == n2) {
        for (i = 0; i < 26; i++) {
            if (a[i] != b[i]) break;
        }
        
        if (i == 26) {
            puts("array");
            
            return 0;
        }
    }
    
    if (n1 > n2) {
        for (i = 0; i < 26; i++) {
            if (a[i] < b[i]) break;
        }
        
        if (i == 26) {
            puts("both");
            
            return 0;
        }
    }
    
    puts("need tree");
    
    return 0;
}