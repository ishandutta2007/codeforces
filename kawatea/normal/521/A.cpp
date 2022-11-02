#include <cstdio>

using namespace std;

int a[4];
char s[100001];

int main()
{
    int n, m = 1000000007, c = 0, sum = 0, i;
    long long ans = 1;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a[0]++;
        } else if (s[i] == 'C') {
            a[1]++;
        } else if (s[i] == 'G') {
            a[2]++;
        } else {
            a[3]++;
        }
    }
    
    for (i = 0; i < 4; i++) {
        if (a[i] > c) {
            c = a[i];
            sum = 1;
        } else if (a[i] == c) {
            sum++;
        }
    }
    
    for (i = 0; i < n; i++) ans = ans * sum % m;
    
    printf("%I64d\n", ans);
    
    return 0;
}