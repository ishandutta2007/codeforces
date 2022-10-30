#include <stdio.h>

int n;

long long bit[300001];

long long sum(int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    
    return s;
}

void add(int i, long long v)
{
    while (i <= n) {
        bit[i] += v;
        i += i & -i;
    }
}

int main()
{
    int k, i;
    char s[300001];
    
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    
    add(1, 1);
    add(2, -1);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '#') continue;
        
        if (sum(i + 1) == 0) continue;
        
        add(i + 2, 1);
        add(i + k + 2, -1);
    }
    
    if (sum(n)) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}