#include <cstdio>

using namespace std;

int a[10];

int main()
{
    int i, j;
    
    for (i = 0; i < 6; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x]++;
    }
    
    for (i = 1; i < 10; i++) {
        if (a[i] >= 4) {
            a[i] -= 4;
            
            for (j = 1; j < 10; j++) {
                if (a[j] == 2) {
                    puts("Elephant");
                    
                    return 0;
                }
            }
            
            puts("Bear");
            
            return 0;
        }
    }
    
    puts("Alien");
    
    return 0;
}