#include <cstdio>
#include <set>

using namespace std;

int a[100000];

int main()
{
    int n, l, x, y, f = 0, i;
    set <int> s;
    
    scanf("%d %d %d %d", &n, &l, &x, &y);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        s.insert(a[i]);
    }
    
    for (i = 0; i < n; i++) {
        if (s.count(a[i] + x)) f |= 1;
        if (s.count(a[i] + y)) f |= 2;
    }
    
    if (f == 3) {
        puts("0");
        
        return 0;
    } else if (f == 1) {
        puts("1");
        printf("%d\n", y);
        
        return 0;
    } else if (f == 2) {
        puts("1");
        printf("%d\n", x);
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (s.count(a[i] + y - x)) {
            if (a[i] >= x) {
                puts("1");
                printf("%d\n", a[i] - x);
                
                return 0;
            } else if (a[i] + y <= l) {
                puts("1");
                printf("%d\n", a[i] + y);
                
                return 0;
            }
        }
        
        if (s.count(a[i] + x + y)) {
            puts("1");
            printf("%d\n", a[i] + x);
            
            return 0;
        }
    }
    
    puts("2");
    printf("%d %d\n", x, y);
    
    return 0;
}