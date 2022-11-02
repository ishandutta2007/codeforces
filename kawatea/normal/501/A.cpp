#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d, x, y;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    x = max(3 * a / 10, a - a / 250 * c);
    y = max(3 * b / 10, b - b / 250 * d);
    
    if (x > y) {
        puts("Misha");
    } else if (x < y) {
        puts("Vasya");
    } else {
        puts("Tie");
    }
    
    return 0;
}