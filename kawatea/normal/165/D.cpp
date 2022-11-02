#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector <int> e[100000];
vector <int> v[100000];
set <int> s[100000];
int a[100000][2];
int b[100000][2];

void dfs(int x, int y, int z, int w)
{
    int i;
    
    a[x][0] = z;
    a[x][1] = w;
    
    for (i = 0; i < e[x].size(); i++) {
        if (e[x][i] == y) continue;
        
        dfs(e[x][i], x, z, w + 1);
    }
}

int main()
{
    int n, m, c = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        e[x].push_back(y);
        e[y].push_back(x);
        
        b[i][0] = x;
        b[i][1] = y;
    }
    
    for (i = 0; i < n; i++) {
        if (e[i].size() > 2) {
            c = i;
            
            break;
        }
    }
    
    for (i = 0; i < e[c].size(); i++) dfs(e[c][i], c, i, 1);
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int x, p, q;
            
            scanf("%d", &x);
            
            x--;
            
            p = b[x][0];
            q = b[x][1];
            
            if (p == c) {
                s[a[q][0]].erase(a[q][1]);
            } else if (q == c) {
                s[a[p][0]].erase(a[p][1]);
            } else {
                s[a[p][0]].erase(max(a[p][1], a[q][1]));
            }
        } else if (t == 2) {
            int x, p, q;
            
            scanf("%d", &x);
            
            x--;
            
            p = b[x][0];
            q = b[x][1];
            
            if (p == c) {
                s[a[q][0]].insert(a[q][1]);
            } else if (q == c) {
                s[a[p][0]].insert(a[p][1]);
            } else {
                s[a[p][0]].insert(max(a[p][1], a[q][1]));
            }
        } else if (t == 3) {
            int x, y;
            set <int>::iterator it;
            
            scanf("%d %d", &x, &y);
            
            x--;
            y--;
            
            if (x == y) {
                puts("0");
                
                continue;
            }
            
            if (x == c) {
                it = s[a[y][0]].lower_bound(0);
                
                if (it == s[a[y][0]].end() || *it > a[y][1]) {
                    printf("%d\n", a[y][1]);
                } else {
                    puts("-1");
                }
            } else if (y == c) {
                it = s[a[x][0]].lower_bound(0);
                
                if (it == s[a[x][0]].end() || *it > a[x][1]) {
                    printf("%d\n", a[x][1]);
                } else {
                    puts("-1");
                }
            } else if (a[x][0] != a[y][0]) {
                it = s[a[x][0]].lower_bound(0);
                
                if (it != s[a[x][0]].end() && *it <= a[x][1]) {
                    puts("-1");
                    
                    continue;
                }
                
                it = s[a[y][0]].lower_bound(0);
                
                if (it != s[a[y][0]].end() && *it <= a[y][1]) {
                    puts("-1");
                    
                    continue;
                }
                
                printf("%d\n", a[x][1] + a[y][1]);
            } else {
                int p = min(a[x][1], a[y][1]);
                int q = max(a[x][1], a[y][1]);
                
                it = s[a[x][0]].lower_bound(p + 1);
                
                if (it == s[a[x][0]].end() || *it > q) {
                    printf("%d\n", q - p);
                } else {
                    puts("-1");
                }
            }
        }
    }
    
    return 0;
}