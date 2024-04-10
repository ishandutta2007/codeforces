#include <stdio.h>

int a[100000];
int b[100000];
char s1[100001];
char s2[100001];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    
    for (i = 0; i < n; i++) s1[i] = s2[i] = '0';
    
    s1[n] = s2[n] = '\0';
    
    for (i = 0; i < n; i++) {
        if (i < n / 2 || a[i] < b[n - i - 1]) s1[i] = '1';
        if (i < n / 2 || b[i] < a[n - i - 1]) s2[i] = '1';
    }
    
    printf("%s\n", s1);
    printf("%s\n", s2);
    
    return 0;
}