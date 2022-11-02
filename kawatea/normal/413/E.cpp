#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int a[2][2];
} data;

const int N = (1 << 18);
data d[2 * N - 1];
char s[2][200001];

data query(int a, int b, int k, int l, int r)
{
    data ans;
    data d1, d2;
    
    if (a <= l && r <= b) return d[k];
    
    if ((l + r) / 2 >= b) return query(a, b, k * 2 + 1, l, (l + r) / 2);
    
    if ((l + r) / 2 <= a) return query(a, b, k * 2 + 2, (l + r) / 2, r);
    
    d1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
    d2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
    
    ans.a[0][0] = ans.a[0][1] = ans.a[1][0] = ans.a[1][1] = 1e8;
    
    ans.a[0][0] = min(ans.a[0][0], d1.a[0][0] + d2.a[0][0] + 1);
    ans.a[0][0] = min(ans.a[0][0], d1.a[0][1] + d2.a[1][0] + 1);
    ans.a[0][1] = min(ans.a[0][1], d1.a[0][0] + d2.a[0][1] + 1);
    ans.a[0][1] = min(ans.a[0][1], d1.a[0][1] + d2.a[1][1] + 1);
    ans.a[1][0] = min(ans.a[1][0], d1.a[1][0] + d2.a[0][0] + 1);
    ans.a[1][0] = min(ans.a[1][0], d1.a[1][1] + d2.a[1][0] + 1);
    ans.a[1][1] = min(ans.a[1][1], d1.a[1][0] + d2.a[0][1] + 1);
    ans.a[1][1] = min(ans.a[1][1], d1.a[1][1] + d2.a[1][1] + 1);
    
    return ans;
}

int main()
{
    int n, m, i, j;
    
    scanf("%d %d", &n, &m);
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    
    for (i = 0; i < 2 * N - 1; i++) d[i].a[0][0] = d[i].a[0][1] = d[i].a[1][0] = d[i].a[1][1] = 1e8;
    
    for (i = 0; i < n; i++) {
        if (s[0][i] == '.') d[i + N - 1].a[0][0] = 0;
        if (s[1][i] == '.') d[i + N - 1].a[1][1] = 0;
        if (s[0][i] == '.' && s[1][i] == '.') d[i + N - 1].a[0][1] = d[i + N - 1].a[1][0] = 1;
    }
    
    for (i = N - 2; i >= 0; i--) {
        d[i].a[0][0] = min(d[i].a[0][0], d[i * 2 + 1].a[0][0] + d[i * 2 + 2].a[0][0] + 1);
        d[i].a[0][0] = min(d[i].a[0][0], d[i * 2 + 1].a[0][1] + d[i * 2 + 2].a[1][0] + 1);
        d[i].a[0][1] = min(d[i].a[0][1], d[i * 2 + 1].a[0][0] + d[i * 2 + 2].a[0][1] + 1);
        d[i].a[0][1] = min(d[i].a[0][1], d[i * 2 + 1].a[0][1] + d[i * 2 + 2].a[1][1] + 1);
        d[i].a[1][0] = min(d[i].a[1][0], d[i * 2 + 1].a[1][0] + d[i * 2 + 2].a[0][0] + 1);
        d[i].a[1][0] = min(d[i].a[1][0], d[i * 2 + 1].a[1][1] + d[i * 2 + 2].a[1][0] + 1);
        d[i].a[1][1] = min(d[i].a[1][1], d[i * 2 + 1].a[1][0] + d[i * 2 + 2].a[0][1] + 1);
        d[i].a[1][1] = min(d[i].a[1][1], d[i * 2 + 1].a[1][1] + d[i * 2 + 2].a[1][1] + 1);
    }
    
    for (i = 0; i < m; i++) {
        int x, y, x1, y1, x2, y2;
        data ans;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        x1 = x % n;
        y1 = x / n;
        x2 = y % n;
        y2 = y / n;
        
        if (x2 < x1) {
            swap(x1, x2);
            swap(y1, y2);
        }
        
        ans = query(x1, x2 + 1, 0, 0, N);
        
        if (ans.a[y1][y2] >= 1e8) ans.a[y1][y2] = -1;
        
        printf("%d\n", ans.a[y1][y2]);
    }
    
    return 0;
}