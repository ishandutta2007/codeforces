#include <cstdio>

using namespace std;

int a[100000];

int main()
{
    int n, k, ans = 0, i;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    if (k % 2 == 0) {
        for (i = 0; i < n; i++) {
            if (a[i] == 2) {
                ans ^= 2;
            } else if (a[i] % 2 == 0 || a[i] == 1) {
                ans ^= 1;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (a[i] == 1 || a[i] == 3) {
                ans ^= 1;
            } else if (a[i] % 2 == 0 && a[i] > 2) {
                int c = 0;
                
                while (a[i] % 2 == 0) {
                    a[i] /= 2;
                    c++;
                }
                
                if (c % 2 == 0 && a[i] != 3) {
                    ans ^= 2;
                } else if (c % 2 == 1 && a[i] == 3) {
                    ans ^= 2;
                } else {
                    ans ^= 1;
                }
            }
        }
    }
    
    if (ans == 0) {
        puts("Nicky");
    } else {
        puts("Kevin");
    }
    
    return 0;
}