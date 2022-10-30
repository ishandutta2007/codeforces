#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
    public:
    
    SegmentTree(int *a, int n) {
        size = 1;
        while (size < n) size <<= 1;
        
        for (int i = 0; i < 60; i++) data[i].resize(size * 2);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 60; j++) {
                if (j % a[i] == 0) {
                    data[j][i + size] = 2;
                } else {
                    data[j][i + size] = 1;
                }
            }
        }
        
        for (int i = size - 1; i > 0; i--) {
            for (int j = 0; j < 60; j++) {
                int x = data[j][i * 2];
                
                data[j][i] = x + data[(j + x) % 60][i * 2 + 1];
            }
        }
    }
    
    ~SegmentTree() {
    }
    
    void update(int x, int v) {
        x += size;
        
        for (int i = 0; i < 60; i++) {
            if (i % v == 0) {
                data[i][x] = 2;
            } else {
                data[i][x] = 1;
            }
        }
        
        while (x > 1) {
            x >>= 1;
            
            for (int i = 0; i < 60; i++) {
                int y = data[i][x * 2];
                
                data[i][x] = y + data[(i + y) % 60][x * 2 + 1];
            }
        }
    }
    
    //[x,y)
    int query(int x, int y) {
        int ans = 0, t = 0;
        vector <int> v;
        
        while (0 < x && x + (x & -x) <= y) {
            ans += data[t][(size + x) / (x & -x)];
            t = (t + data[t][(size + x) / (x & -x)]) % 60;
            x += x & -x;
        }
        
        while (x < y) {
            v.push_back((size + y) / (y & -y) - 1);
            y -= y & -y;
        }
        
        reverse(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++) {
            ans += data[t][v[i]];
            t = (t + data[t][v[i]]) % 60;
        }
        
        return ans;
    }
    
    private:
    
    int size;
    vector <int> data[60];
};

int a[100000];
char c[2];

int main()
{
    int n, q, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    SegmentTree s(a, n);
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y;
        
        scanf("%s %d %d", c, &x, &y);
        
        if (c[0] == 'A') {
            printf("%d\n", s.query(x - 1, y - 1));
        } else {
            s.update(x - 1, y);
        }
    }
    
    return 0;
}