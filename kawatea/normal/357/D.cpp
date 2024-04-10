#include <cstdio>
#include <cstring>

using namespace std;

char s1[1000001];
char s2[1000001];
int a[1000000];
long long b[1000000][26];
long long c[1000000];

int main()
{
    int n1, n2, i, j;
    long long n, m;
    
    scanf("%I64d %I64d", &n, &m);
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n1 = strlen(s1);
    n2 = strlen(s2);
    
    if (n1 == n2) {
        long long sum = 0;
        
        for (i = 0; i < n1; i++) {
            if (s1[i] != s2[i]) sum++;
        }
        
        sum *= n;
        
        printf("%I64d\n", sum);
    } else if (n1 > n2) {
        long long sum = 0;
        
        for (i = 0; i < n1; i++) a[i] = -1;
        
        for (i = 0; i < n2; i++) {
            if (a[i] == -1) {
                int x = i;
                
                while (1) {
                    if (a[x] != -1) break;
                    
                    a[x] = i;
                    b[i][s1[x] - 'a']++;
                    c[i]++;
                    
                    x += n2;
                    x %= n1;
                }
                
                sum += b[i][s2[i] - 'a'] * (m / c[i]);
            } else {
                sum += b[a[i]][s2[i] - 'a'] * (m / c[a[i]]);
            }
        }
        
        sum = n * n1 - sum;
        
        printf("%I64d\n", sum);
    } else {
        long long sum = 0;
        
        for (i = 0; i < n2; i++) a[i] = -1;
        
        for (i = 0; i < n1; i++) {
            if (a[i] == -1) {
                int x = i;
                
                while (1) {
                    if (a[x] != -1) break;
                    
                    a[x] = i;
                    b[i][s2[x] - 'a']++;
                    c[i]++;
                    
                    x += n1;
                    x %= n2;
                }
                
                sum += b[i][s1[i] - 'a'] * (n / c[i]);
            } else {
                sum += b[a[i]][s1[i] - 'a'] * (n / c[a[i]]);
            }
        }
        
        sum = n * n1 - sum;
        
        printf("%I64d\n", sum);
    }
    
    return 0;
}