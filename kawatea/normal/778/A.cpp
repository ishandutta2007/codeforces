#include <cstdio>
#include <cstring>

using namespace std;

char s[200001];
char t[200001];
int a[200000];
int f[200000];

int main() {
    int n, m, l, r, mid, i, j;
    
    scanf("%s", s);
    scanf("%s", t);
    
    n = strlen(s);
    m = strlen(t);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        a[i]--;
    }
    
    l = 0, r = n, mid = (l + r) / 2;
    
    while (r - l > 1) {
        for (i = 0; i < n; i++) f[i] = 0;
        
        for (i = 0; i < mid; i++) f[a[i]] = 1;
        
        for (i = 0, j = 0; i < n && j < m; i++) {
            if (f[i] == 1) continue;
            
            if (s[i] == t[j]) j++;
        }
        
        if (j == m) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    printf("%d\n", l);
    
    return 0;
}