#include <cstdio>
#include <algorithm>

using namespace std;

char s[200001];
char t[200001];
int a[200000];
int b[200000];
int e[200000];
unsigned long long c[3125];
unsigned long long d[64][3126];
int sum[200000];

int main()
{
    int n, m, k, ans = 0, i, j, l;
    
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", s);
    scanf("%s", t);
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a[i] = 0;
        } else if (s[i] == 'T') {
            a[i] = 1;
        } else if (s[i] == 'G') {
            a[i] = 2;
        } else {
            a[i] = 3;
        }
    }
    
    for (i = 0; i < m; i++) {
        if (t[i] == 'A') {
            b[i] = 0;
        } else if (t[i] == 'T') {
            b[i] = 1;
        } else if (t[i] == 'G') {
            b[i] = 2;
        } else {
            b[i] = 3;
        }
    }
    
    for (i = 0; i < 4; i++) {
        unsigned long long x = 0;
        
        for (j = 0; j < n; j++) e[j] = 0;
        
        for (j = 0; j < n; j++) {
            if (a[j] == i) {
                e[max(j - k, 0)]++;
                if (j + k + 1 < n) e[j + k + 1]--;
            }
        }
        
        for (j = 1; j < n; j++) e[j] += e[j - 1];
        
        for (j = 0; j < n; j++) {
            if (e[j] > 0) x |= (1LL << (j % 64));
            
            if (j % 64 == 63) {
                c[j / 64] = x;
                x = 0;
            }
        }
        
        if (j % 64 != 0) c[j / 64] = x;
        
        x = 0;
        
        for (j = 0; j < 64; j++) {
            for (l = 0; l < (m + 63 + 63) / 64; l++) {
                d[j][l] = 0;
            }
        }
        
        for (j = 0; j < m; j++) {
            if (b[j] == i) x |= (1LL << (j % 64));
            
            if (j % 64 == 63) {
                d[0][j / 64] = x;
                x = 0;
            }
        }
        
        if (j % 64 != 0) d[0][j / 64] = x;
        
        for (j = 1; j < 64; j++) {
            int p = 0;
            
            for (l = 0; l < (m + j + 63) / 64; l++) {
                d[j][l] = (d[j - 1][l] << 1) | p;
                p = (d[j - 1][l] >> 63) & 1;
            }
        }
        
        for (j = 0; j < n - m + 1; j++) {
            int x = j / 64, y = j % 64;
            
            for (l = 0; l < (m + y + 63) / 64; l++) {
                if ((c[x + l] & d[y][l]) != d[y][l]) break;
            }
            
            if (l == (m + y + 63) / 64) sum[j]++;
        }
    }
    
    for (i = 0; i < n - m + 1; i++) {
        if (sum[i] == 4) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}