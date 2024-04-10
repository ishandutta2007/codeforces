#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[17];

int main()
{
    int x, y, i;
    vector <int> w;
    
    scanf("%d %d", &x, &y);
    
    for (i = 1; i <= y; i++) v[__builtin_ctz(i)].push_back(i);
    
    while (x) {
        for (i = 16; i >= 0; i--) {
            if (x < (1 << i)) continue;
            if (v[i].size() == 0) continue;
            
            x -= 1 << i;
            w.push_back(v[i].back());
            v[i].pop_back();
            
            break;
        }
        
        if (i < 0) {
            puts("-1");
            
            return 0;
        }
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w[i]);
    }
    
    puts("");
    
    return 0;
}