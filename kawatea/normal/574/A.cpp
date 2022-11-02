#include <cstdio>

using namespace std;

int a[100];

int main()
{
    int n, ans = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    while (1) {
        int c = 1;
        
        for (i = 1; i < n; i++) {
            if (a[i] > a[c]) c = i;
        }
        
        if (a[0] > a[c]) break;
        
        a[0]++;
        a[c]--;
        ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}