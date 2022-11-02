#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

char s[201];
unsigned long long base = 100000007;
unsigned long long power[201];
unsigned long long hash[201];
unsigned long long hash2[10][201];

unsigned long long get(unsigned long long *hash, int x, int y)
{
    return hash[x + y] - hash[x] * power[y];
}

int main()
{
    int n, m, i, j, k, l;
    int a[10][2];
    int b[10];
    char s[201];
    char p[10][201];
    set <unsigned long long> se;
    
    scanf("%s", s);
    
    m = strlen(s);
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s %d %d", p[i], &a[i][0], &a[i][1]);
    
    hash[0] = 0;
    power[0] = 1;
    
    for (i = 0; i < m; i++) {
        hash[i + 1] = hash[i] * base + s[i];
        power[i + 1] = power[i] * base;
    }
    
    for (i = 0; i < n; i++) {
        b[i] = strlen(p[i]);
        
        hash2[i][0] = 0;
        
        for (j = 0; j < b[i]; j++) {
            hash2[i][j + 1] = hash2[i][j] * base + p[i][j];
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = i; j < m; j++) {
            for (k = 0; k < n; k++) {
                int c = 0;
                
                for (l = 0; l <= b[k] - (j - i + 1); l++) {
                    if (get(hash, i, j - i + 1) == get(hash2[k], l, j - i + 1)) c++;
                }
                
                if (c < a[k][0] || c > a[k][1]) break;
            }
            
            if (k == n) se.insert(get(hash, i, j - i + 1));
        }
    }
    
    printf("%d\n", se.size());
    
    return 0;
}