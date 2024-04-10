#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

class SegmentTree {
    public:
    
    SegmentTree(long long *a, int n) {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (long long *)malloc(sizeof(long long) * size * 2);
        
        for (int i = 0; i < size * 2; i++) data[i] = 1e18;
        for (int i = 0; i < n; i++) data[i + size] = a[i];
        for (int i = size - 1; i > 0; i--) data[i] = min(data[i * 2], data[i * 2 + 1]);
    }
    
    ~SegmentTree() {
        free(data);
    }
    
    long long query(int x, int y) {
        long long ans = 1e18;
        
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
    long long *data;
};

class SegmentTree2 {
    public:
    
    SegmentTree2(long long *a, int n) {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (long long *)malloc(sizeof(long long) * size * 2);
        
        for (int i = 0; i < size * 2; i++) data[i] = -1e18;
        for (int i = 0; i < n; i++) data[i + size] = a[i];
        for (int i = size - 1; i > 0; i--) data[i] = max(data[i * 2], data[i * 2 + 1]);
    }
    
    ~SegmentTree2() {
        free(data);
    }
    
    long long query(int x, int y) {
        long long ans = -1e18;
        
        while (0 < x && x + (x & -x) <= y) {
            ans = max(ans, data[(size + x) / (x & -x)]);
            x += x & -x;
        }
        
        while (x < y) {
            ans = max(ans, data[(size + y) / (y & -y) - 1]);
            y -= y & -y;
        }
        
        return ans;
    }
    
    private:
    
    int size;
    long long *data;
};

int a[200000];
int b[200000];
long long c[200000];
long long d[200000];

int main()
{
    int n, m, i;
    long long sum = 0;
    map <long long, int> mp;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < n; i++) {
        a[i + n] = a[i];
        b[i + n] = b[i];
    }
    
    for (i = 0; i < n * 2; i++) {
        c[i] = sum - b[i] * 2;
        d[i] = sum + b[i] * 2;
        mp[sum] = i;
        sum += a[i];
    }
    
    SegmentTree s1(c, n * 2);
    SegmentTree2 s2(d, n * 2);
    
    for (i = 0; i < m; i++) {
        int x, y;
        long long p, q, r, ans;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (x <= y) x += n;
        
        p = s2.query(y + 1, x);
        q = s1.query(y + 1, x);
        r = q + (p - q) / 2;
        
        if ((p - q) % 2 == 0 && mp.count(r) && (long long)b[mp[r]] * 4 == p - q) {
            long long p2 = max(s2.query(y + 1, mp[r]), s2.query(mp[r] + 1, x));
            long long q2 = min(s1.query(y + 1, mp[r]), s1.query(mp[r] + 1, x));
            
            ans = max(p2 - q, p - q2);
        } else {
            ans = p - q;
        }
        
        printf("%I64d\n", ans);
    }
    
    return 0;
}