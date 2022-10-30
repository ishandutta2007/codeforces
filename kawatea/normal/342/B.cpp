#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, m, s, f, x = 0, t = 1, i;
    vector <pair<int, pair<int, int> > > v;
    
    scanf("%d %d %d %d", &n, &m, &s, &f);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        v.push_back(make_pair(x, make_pair(y, z)));
    }
    
    while (1) {
        if (s == f) break;
        
        if (x == v.size() || v[x].first != t) {
            if (s < f) {
                putchar('R');
                
                s++;
            } else {
                putchar('L');
                
                s--;
            }
        } else {
            if (s < f) {
                if ((s >= v[x].second.first && s <= v[x].second.second) || (s + 1 >= v[x].second.first && s + 1 <= v[x].second.second)) {
                    putchar('X');
                } else {
                    putchar('R');
                    
                    s++;
                }
            } else {
                if ((s >= v[x].second.first && s <= v[x].second.second) || (s - 1 >= v[x].second.first && s - 1 <= v[x].second.second)) {
                    putchar('X');
                } else {
                    putchar('L');
                    
                    s--;
                }
            }
            
            x++;
        }
        
        t++;
    }
    
    puts("");
    
    return 0;
}