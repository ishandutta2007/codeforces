#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a1, b1, a2, b2, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    long long x, y;
    
    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);
    
    x = (long long)a1 * b1;
    y = (long long)a2 * b2;
    
    while (x % 2 == 0) {
        x /= 2;
        c1++;
    }
    
    while (x % 3 == 0) {
        x /= 3;
        c1++;
        d1++;
    }
    
    while (y % 2 == 0) {
        y /= 2;
        c2++;
    }
    
    while (y % 3 == 0) {
        y /= 3;
        c2++;
        d2++;
    }
    
    if (x != y) {
        puts("-1");
        
        return 0;
    }
    
    printf("%d\n", abs(c1 - c2) + abs(d1 - d2));
    
    while (d1 > d2) {
        if (a1 % 3 == 0) {
            a1 /= 3;
            a1 *= 2;
        } else {
            b1 /= 3;
            b1 *= 2;
        }
        
        d1--;
    }
    
    while (d1 < d2) {
        if (a2 % 3 == 0) {
            a2 /= 3;
            a2 *= 2;
        } else {
            b2 /= 3;
            b2 *= 2;
        }
        
        d2--;
    }
    
    while (c1 > c2) {
        if (a1 % 2 == 0) {
            a1 /= 2;
        } else {
            b1 /= 2;
        }
        
        c1--;
    }
    
    while (c1 < c2) {
        if (a2 % 2 == 0) {
            a2 /= 2;
        } else {
            b2 /= 2;
        }
        
        c2--;
    }
    
    printf("%d %d\n", a1, b1);
    printf("%d %d\n", a2, b2);
    
    return 0;
}