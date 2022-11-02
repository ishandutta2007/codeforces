#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

unsigned long long base = 100000007;
unsigned long long power[2001];
unsigned long long hash[2001];
unsigned long long hash2[10][2001];

unsigned long long get(unsigned long long *hash, int x, int y)
{
    return hash[x + y] - hash[x] * power[y];
}

int main()
{
    int n, m, i, j, k, l;
    int a[10][2];
    int b[10];
    char s[2001];
    char p[10][2001];
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
        int d[2001] = {0};
        
        for (j = 0; j < n; j++) {
            int l1, r1, m1, l2, r2, m2;
            
            l1 = i - 1, r1 = m, m1 = (l1 + r1) / 2;
            
            while (r1 - l1 > 1) {
                int c = 0;
                
                for (k = 0; k <= b[j] - (m1 - i + 1); k++) {
                    if (get(hash, i, m1 - i + 1) == get(hash2[j], k, m1 - i + 1)) c++;
                }
                
                if (c >= a[j][0]) {
                    l1 = m1;
                    m1 = (l1 + r1) / 2;
                } else {
                    r1 = m1;
                    m1 = (l1 + r1) / 2;
                }
            }
            
            l2 = i - 1, r2 = m, m2 = (l2 + r2) / 2;
            
            while (r2 - l2 > 1) {
                int c = 0;
                
                for (k = 0; k <= b[j] - (m2 - i + 1); k++) {
                    if (get(hash, i, m2 - i + 1) == get(hash2[j], k, m2 - i + 1)) c++;
                }
                
                if (c <= a[j][1]) {
                    r2 = m2;
                    m2 = (l2 + r2) / 2;
                } else {
                    l2 = m2;
                    m2 = (l2 + r2) / 2;
                }
            }
            
            if (l1 < r2) break;
            
            d[r2]++;
            d[l1 + 1]--;
        }
        
        for (j = i; j < m; j++) d[j] += d[j - 1];
        
        for (j = i; j < m; j++) {
            if (d[j] == n) {
                se.insert(get(hash, i, j - i + 1));
            }
        }
    }
    
    printf("%d\n", se.size());
    
    return 0;
}