#include <cstdio>

using namespace std;

int f[1000001];

int main()
{
    int a, m, i;
    
    scanf("%d %d", &a, &m);
    
    while (1) {
        if (a == 0) {
            puts("Yes");
            
            return 0;
        }
        
        if (f[a] == 1) {
            puts("No");
            
            return 0;
        }
        
        f[a] = 1;
        a = (a + a % m) % m;
    }
    
    return 0;
}