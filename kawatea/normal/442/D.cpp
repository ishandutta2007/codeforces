#include <cstdio>
#include <algorithm>

using namespace std;

pair <int, int> a[1000001][2];
int p[1000001];

void dfs(int x)
{
    while (x > 0) {
        int y = p[x];
        int c = max(a[x][0].first, a[x][1].first + 1);
        
        if (a[y][0].second == x) {
            if (a[y][0].first < c) {
                a[y][0].first = c;
            } else {
                break;
            }
        } else if (a[y][1].second == x) {
            if (a[y][1].first < c) {
                a[y][1].first = c;
            } else {
                break;
            }
        } else if (a[y][1].first < c) {
            a[y][1] = make_pair(c, x);
        } else {
            break;
        }
        
        if (a[y][0].first < a[y][1].first) swap(a[y][0], a[y][1]);
        
        x = y;
    }
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        x--;
        
        p[i + 1] = x;
        
        dfs(i + 1);
        
        if (i > 0) putchar(' ');
        printf("%d", a[0][0].first);
    }
    
    puts("");
    
    return 0;
}