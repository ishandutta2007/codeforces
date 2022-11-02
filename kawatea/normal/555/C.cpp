#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class SegmentTree {
    public:
    
    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        
        data = (int *)malloc(sizeof(int) * size * 2);
        
        for (int i = 0; i < size * 2; i++) data[i] = 2e9;
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
    
    int query(int x, int y) {
        int ans = 2e9;
        
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

char s[2];
int a[200000][3];
int b[200000];
int c[200000];
int f[200000];

int main()
{
    int n, q, i;
    map <int, int> mpx, mpy;
    map <int, int>::iterator it;
    
    scanf("%d %d", &n, &q);
    
    for (i = 0; i < q; i++) {
        int x, y;
        
        scanf("%d %d %s", &y, &x, s);
        
        a[i][0] = x;
        a[i][1] = y;
        if (s[0] == 'L') a[i][2] = 1;
        
        mpx[x]++;
        mpy[y]++;
    }
    
    for (it = mpx.begin(), i = 0; it != mpx.end(); it++, i++) {
        it->second = i;
        b[i] = it->first;
    }
    
    for (it = mpy.begin(), i = 0; it != mpy.end(); it++, i++) {
        it->second = i;
        c[i] = it->first;
    }
    
    SegmentTree sx(mpy.size() + 1);
    SegmentTree sy(mpx.size() + 1);
    
    for (i = 0; i < q; i++) {
        int x = mpx[a[i][0]];
        int y = mpy[a[i][1]];
        
        if (f[x] == 1) {
            puts("0");
            
            continue;
        }
        
        f[x] = 1;
        
        if (a[i][2] == 0) {
            if (sy.query(0, x) > y) {
                printf("%d\n", a[i][0]);
                
                sx.update(y, 0);
            } else {
                int l = 0, r = x, m = (l + r) / 2;
                
                while (r - l > 1) {
                    if (sy.query(m, x) > y) {
                        r = m;
                        m = (l + r) / 2;
                    } else {
                        l = m;
                        m = (l + r) / 2;
                    }
                }
                
                printf("%d\n", a[i][0] - b[r - 1]);
                
                sx.update(y, r);
            }
        } else {
            if (sx.query(0, y) > x) {
                printf("%d\n", a[i][1]);
                
                sy.update(x, 0);
            } else {
                int l = 0, r = y, m = (l + r) / 2;
                
                while (r - l > 1) {
                    if (sx.query(m, y) > x) {
                        r = m;
                        m = (l + r) / 2;
                    } else {
                        l = m;
                        m = (l + r) / 2;
                    }
                }
                
                printf("%d\n", a[i][1] - c[r - 1]);
                
                sy.update(x, r);
            }
        }
    }
    
    return 0;
}