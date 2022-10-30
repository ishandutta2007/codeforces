#include <cstdio>
#include <vector>

using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];

int main()
{
    int n, t, p = 0, i;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int x;
        
        scanf("%d", &x);
        
        b[x - 1] = 1;
    }
    
    for (i = n - 1; i >= 0; i--) {
        if (v.size() > 0 && v.back() == a[i] && b[i] == 0) {
            v.pop_back();
            c[i] = 1;
        } else {
            v.push_back(a[i]);
        }
    }
    
    if (v.size() == 0) {
        puts("YES");
        
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            if (c[i] == 1) {
                printf("%d", a[i]);
            } else {
                printf("%d", -a[i]);
            }
        }
        
        puts("");
    } else {
        puts("NO");
    }
    
    return 0;
}