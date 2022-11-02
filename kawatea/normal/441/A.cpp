#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, v, i, j;
    vector <int> w;
    
    scanf("%d %d", &n, &v);
    
    for (i = 0; i < n; i++) {
        int k, f = 0;
        
        scanf("%d", &k);
        
        for (j = 0; j < k; j++) {
            int x;
            
            scanf("%d", &x);
            
            if (x < v) f = 1;
        }
        
        if (f == 1) w.push_back(i + 1);
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w[i]);
    }
    
    puts("");
    
    return 0;
}