#include <stdio.h>

char s1[2000001];
char s2[2000001];

int main()
{
    int n, x = 0, y = 0, i, j;
    int a[4] = {0};
    
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    
    for (i = 0; i < 2 * n; i++) {
        if (s1[i] == '1') {
            if (s2[i] == '1') {
                a[0]++;
            } else {
                a[1]++;
            }
        } else {
            if (s2[i] == '1') {
                a[2]++;
            } else {
                a[3]++;
            }
        }
    }
    
    for (i = 0; i < 2 * n; i++) {
        for (j = 0; j < 4; j++) {
            if (a[j] == 0) continue;
            
            if (i % 2 == 0) {
                if (j < 2) x++;
            } else {
                if (j % 2 == 0) y++;
            }
            
            a[j]--;
            
            break;
        }
    }
    
    if (x > y) {
        puts("First");
    } else if (x == y) {
        puts("Draw");
    } else {
        puts("Second");
    }
    
    return 0;
}