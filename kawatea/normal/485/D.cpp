#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
    public:
    
    SegmentTree(int n)
    {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (int *)malloc(sizeof(int *) * size * 2);
        
        for (int i = 0; i < size * 2; i++) data[i] = 0;
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
            data[x] = max(data[x * 2], data[x * 2 + 1]);
        }
    }
    
    int query(int x, int y)
    {
        int ans = 0;
        
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
    int *data;
};

int main()
{
    int n, ans = 0, i, j;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    SegmentTree s(1000001);
    
    for (i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) continue;
        
        s.update(v[i], v[i]);
        
        for (j = v[i]; j <= 1000000; j += v[i]) {
            int x = s.query(j, min(j + v[i], 1000001));
            
            ans = max(ans, x - j);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}