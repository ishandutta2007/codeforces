#include <cstdio>

using namespace std;

int a[100000];
int b[100000];
int c[100001];

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = n - 1; i >= 0; i--) {
        a[i]--;
        
        if (b[a[i]] == 0) c[i]++;
        
        b[a[i]]++;
        
        c[i] += c[i + 1];
    }
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        printf("%d\n", c[x - 1]);
    }
    
    return 0;
}