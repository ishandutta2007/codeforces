#include <cstdio>
#include <cstdlib>

using namespace std;

unsigned long long m = 1000000007;

class Hash {
    public:
    
    Hash(const int *a, int n, unsigned long long base = 1000000007)
    {
        hash = (unsigned long long *)malloc(sizeof(unsigned long long) * (n + 1));
        pow = (unsigned long long *)malloc(sizeof(unsigned long long) * (n + 1));
        
        hash[0] = 0;
        pow[0] = 1;
        
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + a[i]) % m;
            pow[i + 1] = pow[i] * base % m;
        }
    }
    
    ~Hash() {
        free(hash);
        free(pow);
    }
    
    unsigned long long get(int x, int y)
    {
        return (hash[x + y] - hash[x] * pow[y] % m + m) % m;
    }
    
    private:
    
    unsigned long long *hash;
    unsigned long long *pow;
};

int a[200000];
int b[200000];

int main()
{
    int n, w, ans = 0, i;
    unsigned long long x = 0, y = 1;
    
    scanf("%d %d", &n, &w);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < w; i++) scanf("%d", &b[i]);
    
    Hash h1(a, n, 1009);
    Hash h2(b, w, 1009);
    
    for (i = 0; i < w; i++) {
        x = (x + y) % m;
        y = y * 1009 % m;
    }
    
    for (i = 0; i + w <= n; i++) {
        int z = a[i] - b[0];
        
        if (z < 0) z += m;
        
        if (h1.get(i, w) == (h2.get(0, w) + x * z % m + m) % m) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}