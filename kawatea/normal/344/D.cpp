#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n, x = 0, y, i;
    char s[100001];
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (n % 2 == 1) {
        puts("No");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (x == 0) {
            if (s[i] == '+') {
                y = 0;
            } else {
                y = 1;
            }
            
            x = 1;
        } else {
            if (s[i] == '+') {
                if ((x + y) % 2 == 1) {
                    x--;
                } else {
                    x++;
                }
            } else {
                if ((x + y) % 2 == 0) {
                    x--;
                } else {
                    x++;
                }
            }
        }
    }
    
    if (x == 0) {
        puts("Yes");
    } else {
        puts("No");
    }
    
    return 0;
}