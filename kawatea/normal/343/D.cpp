#include <cstdio>
#include <vector>

using namespace std;

const int N = (1 << 20);
int d1[2 * N - 1];
int d2[2 * N - 1];

void update_a(int a, int b, int v, int k, int l, int r)
{
    if (r <= a || b <= l) return;
    
    if (a <= l && r <= b) {
        d1[k] = v;
        
        return;
    } else {
        update_a(a, b, v, k * 2 + 1, l, (l + r) / 2);
        update_a(a, b, v, k * 2 + 2, (l + r) / 2, r);
    }
}

int query_a(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return -1;
    
    if (a <= l && r <= b) return d1[k];
    
    return max(d1[k], max(query_a(a, b, k * 2 + 1, l, (l + r) / 2), query_a(a, b, k * 2 + 2, (l + r) / 2, r)));
}

void update_b(int k, int a)
{
    k += N - 1;
    
    d2[k] = a;
    
    while (k > 0) {
        k = (k - 1) / 2;
        d2[k] = max(d2[k * 2 + 1], d2[k * 2 + 2]);
    }
}

int query_b(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return 0;
    
    if (a <= l && r <= b) return d2[k];
    
    return max(query_b(a, b, k * 2 + 1, l, (l + r) / 2), query_b(a, b, k * 2 + 2, (l + r) / 2, r));
}

int c;
int d[500000][2];
vector <int> v[500000];

void dfs(int x, int y)
{
    int i;
    
    d[x][0] = c++;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        dfs(v[x][i], x);
    }
    
    d[x][1] = c++;
}

int main()
{
    int n, q, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(0, -1);
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        y--;
        
        if (x == 1) {
            update_a(d[y][0], d[y][1] + 1, i + 1, 0, 0, N);
        } else if (x == 2) {
            update_b(d[y][0], i + 1);
        } else {
            int z = query_a(d[y][0], d[y][0] + 1, 0, 0, N);
            int w = query_b(d[y][0], d[y][1] + 1, 0, 0, N);
            
            if (z > w) {
                puts("1");
            } else {
                puts("0");
            }
        }
    }
    
    return 0;
}