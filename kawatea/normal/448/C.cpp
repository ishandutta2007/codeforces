#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class SegmentTree {
    public:
    
    SegmentTree(int *a, int n)
    {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (int *)malloc(sizeof(int *) * size * 2);
        
        for (int i = 0; i < size * 2; i++) data[i] = 1e9;
        for (int i = 0; i < n; i++) data[i + size] = a[i];
        for (int i = size - 1; i > 0; i--) data[i] = min(data[i * 2], data[i * 2 + 1]);
    }
    
    ~SegmentTree() {
        free(data);
    }
    
    void update(int x, int v)
    {
        x += size;
        data[x] = v;
        
        while (x > 1) {
            x >>= 1;
            data[x] = min(data[x * 2], data[x * 2 + 1]);
        }
    }
    
    int query(int x, int y)
    {
        int ans = 1e9;
        
        while (0 < x && x + (x & -x) <= y) {
            ans = min(ans, data[(size + x) / (x & -x)]);
            x += x & -x;
        }
        
        while (x < y) {
            ans = min(ans, data[(size + y) / (y & -y) - 1]);
            y -= y & -y;
        }
        
        return ans;
    }
    
    private:
    
    int size;
    int *data;
};

int a[5000];

int dfs(int x, int y, int z, SegmentTree &s)
{
    int ans = y - x, sum, p, i, j;
    
    p = s.query(x, y);
    
    if (p - z >= ans) return ans;
    
    sum = p - z;
    
    for (i = x; i < y; i++) {
        if (a[i] == p) continue;
        
        for (j = i + 1; j < y; j++) {
            if (a[j] == p) break;
        }
        
        sum += dfs(i, j, p, s);
        
        i = j;
    }
    
    return min(ans, sum);
}

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    SegmentTree s(a, n);
    
    printf("%d\n", dfs(0, n, 0, s));
    
    return 0;
}