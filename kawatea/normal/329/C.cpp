#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int a[10][10];
set <int> s[100000];

int main()
{
    int n, m, i;
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    if (n <= 10) {
        for (i = 0; i < m; i++) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            x--;
            y--;
            
            a[x][y] = a[y][x] = 1;
        }
        
        for (i = 0; i < n; i++) v.push_back(i);
        
        do {
            int c = 0;
            
            for (i = 0; i < n; i++) {
                int x = v[i];
                int y = v[(i + 1) % n];
                
                if (a[x][y] == 0) c++;
            }
            
            if (c >= m) {
                for (i = 0; i < n && m > 0; i++) {
                    int x = v[i];
                    int y = v[(i + 1) % n];
                    
                    if (a[x][y] == 0) {
                        m--;
                        printf("%d %d\n", x + 1, y + 1);
                    }
                }
                
                return 0;
            }
        } while (next_permutation(v.begin(), v.end()));
        
        puts("-1");
    } else {
        for (i = 0; i < m; i++) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            x--;
            y--;
            
            s[x].insert(y);
            s[y].insert(x);
        }
        
        for (i = 0; i < n; i++) v.push_back(i);
        
        while (1) {
            int c = 0;
            
            for (i = 0; i < n; i++) {
                int x = v[i];
                int y = v[(i + 1) % n];
                
                if (!s[x].count(y)) c++;
            }
            
            if (c >= m) {
                for (i = 0; i < n && m > 0; i++) {
                    int x = v[i];
                    int y = v[(i + 1) % n];
                    
                    if (!s[x].count(y)) {
                        m--;
                        printf("%d %d\n", x + 1, y + 1);
                    }
                }
                
                return 0;
            }
            
            random_shuffle(v.begin(), v.end());
        }
    }
    
    return 0;
}