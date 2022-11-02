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
        
        data = (long long *)malloc(sizeof(long long) * size * 2);
        data2 = (int *)malloc(sizeof(int) * size * 2);
        data3 = (int *)malloc(sizeof(int) * size * 2);
        
        for (int i = 0; i < size * 2; i++) {
            data[i] = 0;
            data2[i] = -1;
            data3[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            data[i + size] = data2[i + size] = a[i];
            data3[i + size] = i;
        }
        for (int i = size - 1; i > 0; i--) {
            data[i] = data[i * 2] + data[i * 2 + 1];
            data2[i] = max(data2[i * 2], data2[i * 2 + 1]);
            if (data2[i * 2] >= data2[i * 2 + 1]) {
                data3[i] = data3[i * 2];
            } else {
                data3[i] = data3[i * 2 + 1];
            }
        }
    }
    
    ~SegmentTree() {
        free(data);
        free(data2);
        free(data3);
    }
    
    void update(int x, int v)
    {
        x += size;
        data[x] = data2[x] = v;
        
        while (x > 1) {
            x >>= 1;
            data[x] = data[x * 2] + data[x * 2 + 1];
            data2[x] = max(data2[x * 2], data2[x * 2 + 1]);
            if (data2[x * 2] >= data2[x * 2 + 1]) {
                data3[x] = data3[x * 2];
            } else {
                data3[x] = data3[x * 2 + 1];
            }
        }
    }
    
    long long query(int x, int y)
    {
        long long ans = 0;
        
        while (0 < x && x + (x & -x) <= y) {
            ans += data[(size + x) / (x & -x)];
            x += x & -x;
        }
        
        while (x < y) {
            ans += data[(size + y) / (y & -y) - 1];
            y -= y & -y;
        }
        
        return ans;
    }
    
    pair<int, int> query2(int x, int y)
    {
        int ans = 1e9, num = -1;
        
        while (0 < x && x + (x & -x) <= y) {
            if (data2[(size + x) / (x & -x)] > num) {
                num = data2[(size + x) / (x & -x)];
                ans = data3[(size + x) / (x & -x)];
            } else if (data2[(size + x) / (x & -x)] == num) {
                ans = min(ans, data3[(size + x) / (x & -x)]);
            }
            x += x & -x;
        }
        
        while (x < y) {
            if (data2[(size + y) / (y & -y) - 1] > num) {
                num = data2[(size + y) / (y & -y) - 1];
                ans = data3[(size + y) / (y & -y) - 1];
            } else if (data2[(size + y) / (y & -y) - 1] == num) {
                ans = min(ans, data3[(size + y) / (y & -y) - 1]);
            }
            y -= y & -y;
        }
        
        return make_pair(ans, num);
    }
    
    private:
    
    int size;
    long long *data;
    int *data2;
    int *data3;
};

int a[100000];

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    SegmentTree s(a, n);
    
    for (i = 0; i < m; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            printf("%I64d\n", s.query(x - 1, y));
        } else if (t == 2) {
            int x, y, z;
            
            scanf("%d %d %d", &x, &y, &z);
            
            while (1) {
                pair <int, int> p = s.query2(x - 1, y);
                
                if (p.second < z) break;
                
                s.update(p.first, p.second % z);
            }
        } else {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            s.update(x - 1, y);
        }
    }
    
    return 0;
}