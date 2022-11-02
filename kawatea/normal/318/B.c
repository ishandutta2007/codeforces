#include <stdio.h>
#include <string.h>

char s[1000001];
int a[1000001];
int b[1000001];

int main()
{
    int n, i;
    long long sum = 0;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (strncmp(&s[i], "heavy", 5) == 0) a[i]++;
        if (strncmp(&s[i], "metal", 5) == 0) b[i]++;
    }
    
    for (i = n - 1; i >= 0; i--) b[i] += b[i + 1];
    
    for (i = 0; i < n; i++) sum += (long long)a[i] * b[i];
    
    printf("%I64d\n", sum);
    
    return 0;
}