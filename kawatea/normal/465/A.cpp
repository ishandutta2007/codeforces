#include <cstdio>

using namespace std;

char s[101];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            printf("%d\n", i + 1);
            
            return 0;
        }
    }
    
    printf("%d\n", n);
    
    return 0;
}