#include <cstdio>
#include <cstdlib>

using namespace std;

class Bit {
    public:
    
    Bit(int n)
    {
        size = n + 1;
        bit = (long long *)calloc(size, sizeof(long long));
    }
    
    ~Bit() {
        free(bit);
    }
    
    void add(int x, long long v)
    {
        for (x++; x < size; x += x & -x) bit[x] += v;
    }
    
    //[0,x]
    long long sum(int x)
    {
        long long s = 0;
        
        for (x++; x > 0; x -= x & -x) s += bit[x];
        
        return s;
    }
    
    //[x,y]
    long long get(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
    
    private:
    
    int size;
    long long *bit;
};


int main()
{
    int n, q, f = 0, l = 0, i, j;
    
    scanf("%d %d", &n, &q);
    
    Bit b(n);
    
    for (i = 0; i < n; i++) b.add(i, 1);
    
    for (i = 0; i < q; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 1) {
            int y;
            
            scanf("%d", &y);
            
            if (f == 0) {
                if (y * 2 <= n) {
                    for (j = 0; j < y; j++) {
                        int p = b.get(l + j, l + j);
                        
                        b.add(l + y * 2 - j - 1, p);
                        b.add(l + j, -p);
                    }
                    
                    l += y;
                    n -= y;
                } else {
                    y = n - y;
                    
                    for (j = 0; j < y; j++) {
                        int p = b.get(l + n - j - 1, l + n - j - 1);
                        
                        b.add(l + n - y * 2 + j, p);
                        b.add(l + n - j - 1, -p);
                    }
                    
                    n -= y;
                    f = 1;
                }
            } else {
                if (y * 2 <= n) {
                    for (j = 0; j < y; j++) {
                        int p = b.get(l + n - j - 1, l + n - j - 1);
                        
                        b.add(l + n - y * 2 + j, p);
                        b.add(l + n - j - 1, -p);
                    }
                    
                    n -= y;
                } else {
                    y = n - y;
                    
                    for (j = 0; j < y; j++) {
                        int p = b.get(l + j, l + j);
                        
                        b.add(l + y * 2 - j - 1, p);
                        b.add(l + j, -p);
                    }
                    
                    l += y;
                    n -= y;
                    f = 0;
                }
            }
        } else {
            int y, z;
            
            scanf("%d %d", &y, &z);
            
            if (f == 0) {
                printf("%d\n", b.get(l + y, l + z - 1));
            } else {
                printf("%d\n", b.get(l + n - z, l + n - y - 1));
            }
        }
    }
    
    return 0;
}