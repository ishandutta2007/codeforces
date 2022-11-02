#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (1 << 19);
int d[2 * N - 1];
int a[300000][3];

void update(int a, int b, int v, int k, int l, int r)
{
    if (r <= a || b <= l) return;
    
    if (a <= l && r <= b) {
        d[k] = v;
        
        return;
    } else {
        update(a, b, v, k * 2 + 1, l, (l + r) / 2);
        update(a, b, v, k * 2 + 2, (l + r) / 2, r);
    }
}

int query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return 1e9;
    
    if (a <= l && r <= b) return d[k];
    
    return min(d[k], min(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r)));
}

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    
    for (i = 0; i < 2 * N - 1; i++) d[i] = 1e9;
    
    for (i = m - 1; i >= 0; i--) {
        a[i][0]--;
        a[i][1]--;
        a[i][2]--;
        
        update(a[i][0], a[i][2], i + 1, 0, 0, N);
        update(a[i][2] + 1, a[i][1] + 1, i + 1, 0, 0, N);
    }
    
    for (i = 0; i < n; i++) {
        int x = query(i, i + 1, 0, 0, N);
        
        if (i > 0) putchar(' ');
        
        if (x != 1e9) {
            x = a[x - 1][2] + 1;
        } else {
            x = 0;
        }
        
        printf("%d", x);
    }
    
    puts("");
    
    return 0;
}