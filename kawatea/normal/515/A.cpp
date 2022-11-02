#include <cstdio>

using namespace std;

int main()
{
    int a, b, s;
    
    scanf("%d %d %d", &a, &b, &s);
    
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (a + b > s || (s - a - b) % 2 == 1) {
        puts("No");
    } else {
        puts("Yes");
    }
    
    return 0;
}