#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class SegmentTree {
    public:
    
    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (int *)malloc(sizeof(int *) * size * 2);
        
        for (int i = 0; i < size * 2; i++) data[i] = 1e9;
    }
    
    ~SegmentTree() {
        free(data);
    }
    
    void update(int x, int v) {
        x += size;
        data[x] = v;
        
        while (x > 1) {
            x >>= 1;
            data[x] = min(data[x * 2], data[x * 2 + 1]);
        }
    }
    
    //[x,y)
    int query(int x, int y) {
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

class SegmentTree2 {
    public:
    
    SegmentTree2(int *a, int n) {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (int *)malloc(sizeof(int *) * size * 2);
        data2 = (int *)malloc(sizeof(int *) * size * 2);
        
        for (int i = 0; i < size * 2; i++) {
            data[i] = -1e9;
            data2[i] = 1e9;
        }
        for (int i = 0; i < n; i++) data[i + size] = data2[i + size] = a[i];
        for (int i = size - 1; i > 0; i--) {
            data[i] = max(data[i * 2], data[i * 2 + 1]);
            data2[i] = min(data2[i * 2], data2[i * 2 + 1]);
        }
    }
    
    ~SegmentTree2() {
        free(data);
        free(data2);
    }
    
    //[x,y)
    int query(int x, int y) {
        int ans = -1e9, ans2 = 1e9;
        
        while (0 < x && x + (x & -x) <= y) {
            ans = max(ans, data[(size + x) / (x & -x)]);
            ans2 = min(ans2, data2[(size + x) / (x & -x)]);
            x += x & -x;
        }
        
        while (x < y) {
            ans = max(ans, data[(size + y) / (y & -y) - 1]);
            ans2 = min(ans2, data2[(size + y) / (y & -y) - 1]);
            y -= y & -y;
        }
        
        return ans - ans2;
    }
    
    private:
    
    int size;
    int *data;
    int *data2;
};

int a[100000];

int main()
{
    int n, s, l, i;
    
    scanf("%d %d %d", &n, &s, &l);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    SegmentTree2 s1(a, n);
    SegmentTree dp(n + 1);
    
    dp.update(0, 0);
    
    for (i = l - 1; i < n; i++) {
        int l1, r1, m;
        
        if (s1.query(i - l + 1, i + 1) > s) continue;
        
        l1 = -1, r1 = i - l + 1, m = (l1 + r1) / 2;
        
        while (r1 - l1 > 1) {
            if (s1.query(m, i + 1) > s) {
                l1 = m;
                m = (l1 + r1) / 2;
            } else {
                r1 = m;
                m = (l1 + r1) / 2;
            }
        }
        
        dp.update(i + 1, dp.query(r1, i - l + 2) + 1);
    }
    
    if (dp.query(n, n + 1) >= 1e9) {
        puts("-1");
    } else {
        printf("%d\n", dp.query(n, n + 1));
    }
    
    return 0;
}