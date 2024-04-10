#include <cstdio>
#include <cstdlib>

using namespace std;

class Bit {
    public:
    
    Bit(int n) {
        size = n + 1;
        high = 1 << (31 - __builtin_clz(n));
        bit = (long long *)calloc(size, sizeof(long long));
    }
    
    ~Bit() {
        free(bit);
    }
    
    void add(int x, long long v) {
        for (x++; x < size; x += x & -x) bit[x] += v;
    }
    
    //[0,x]
    long long sum(int x) {
        long long s = 0;
        
        for (x++; x > 0; x -= x & -x) s += bit[x];
        
        return s;
    }
    
    //[x,y]
    long long get(int x, int y) {
        return sum(y) - sum(x - 1);
    }
    
    //[0,x]vx
    int find(long long v) {
        int x = 0;
        
        for (int i = high; i > 0; i >>= 1) {
            if (x + i < size && bit[x + i] <= v) {
                x += i;
                v -= bit[x];
            }
        }
        
        return x;
    }
    
    private:
    
    int size;
    int high;
    long long *bit;
};

int a[200000];
int b[200000];
int c[200000];
int d[200000];
int e[200000];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    Bit b1(n);
    
    for (i = 0; i < n; i++) b1.add(i, 1);
    
    for (i = 0; i < n; i++) {
        c[i] = b1.sum(a[i]) - 1;
        
        b1.add(a[i], -1);
    }
    
    Bit b2(n);
    
    for (i = 0; i < n; i++) b2.add(i, 1);
    
    for (i = 0; i < n; i++) {
        d[i] = b2.sum(b[i]) - 1;
        
        b2.add(b[i], -1);
    }
    
    for (i = n - 1; i >= 0; i--) {
        e[i] += c[i] + d[i];
        
        if (e[i] >= n - i) {
            e[i] -= n - i;
            if (i > 0) e[i - 1]++;
        }
    }
    
    Bit b3(n);
    
    for (i = 0; i < n; i++) b3.add(i, 1);
    
    for (i = 0; i < n; i++) {
        int x = b3.find(e[i]);
        
        b3.add(x, -1);
        
        if (i > 0) putchar(' ');
        
        printf("%d", x);
    }
    
    puts("");
    
    return 0;
}