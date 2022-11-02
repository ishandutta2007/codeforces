#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
const long long mod2 = (long long)mod * mod;

class Vector {
    public:
    
    int n;
    int *data;
    
    Vector(int n)
    {
        this->n = n;
        data = (int *)calloc(n, sizeof(int));
    }
    
    Vector(const Vector &v)
    {
        n = v.n;
        data = (int *)malloc(sizeof(int) * n);
        
        for (int i = 0; i < n; i++) data[i] = v.data[i];
    }
    
    ~Vector()
    {
        free(data);
    }
    
    Vector& operator=(const Vector &v)
    {
        free(data);
        
        n = v.n;
        data = (int *)malloc(sizeof(int) * n);
        
        for (int i = 0; i < n; i++) data[i] = v.data[i];
        
        return *this;
    }
    
    int& operator[](int x)
    {
        return data[x];
    }
    
    const int operator*(const Vector &v) const
    {
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans += (long long)data[i] * v.data[i];
            if (ans >= mod2) ans -= mod2;
        }
        
        return ans % mod;
    }
};

class Matrix {
    public:
    
    int n;
    int m;
    int *data;
    
    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;
        data = (int *)calloc(n * m, sizeof(int));
    }
    
    Matrix(const Matrix &a)
    {
        n = a.n;
        m = a.m;
        data = (int *)malloc(sizeof(int) * n * m);
        
        for (int i = 0; i < n * m; i++) data[i] = a.data[i];
    }
    
    ~Matrix()
    {
        free(data);
    }
    
    Matrix& operator=(const Matrix &a)
    {
        free(data);
        
        n = a.n;
        m = a.m;
        data = (int *)malloc(sizeof(int) * n * m);
        
        for (int i = 0; i < n * m; i++) data[i] = a.data[i];
        
        return *this;
    }
    
    int* operator[](int x)
    {
        return data + x * m;
    }
    
    void identify(void)
    {
        for (int i = 0, j = 0; i < n; i++, j += m + 1) data[j] = 1;
    }
    
    const Vector operator*(const Vector &v) const
    {
        Vector ans(n);
        
        for (int i = 0, k = 0; i < n; i++) {
            long long sum = 0;
            
            for (int j = 0; j < m; j++, k++) {
                sum += (long long)data[k] * v.data[j];
                if (sum >= mod2) sum -= mod2;
            }
            
            ans.data[i] = sum % mod;
        }
        
        return ans;
    }
    
    const Matrix operator*(const Matrix &a) const
    {
        int *tmp = (int *)malloc(sizeof(int) * a.n * a.m);
        Matrix ans(n, a.m);
        
        for (int i = 0; i < a.m; i++) {
            for (int j = 0; j < a.n; j++) {
                tmp[i * a.n + j] = a.data[j * a.m + i];
            }
        }
        
        for (int i = 0, l = 0; i < n; i++) {
            int *p1 = data + i * m;
            int *p2 = tmp;
            
            for (int j = 0; j < a.m; j++, l++, p2 += m) {
                int *pa = p1;
                int *pb = p2;
                long long sum = 0;
                
                for (int k = 0; k < m; k++, pa++, pb++) {
                    sum += (long long)*pa * *pb;
                    if (sum >= mod2) sum -= mod2;
                }
                
                ans.data[l] = sum % mod;
            }
        }
        
        free(tmp);
        
        return ans;
    }
    
    void operator*=(const Matrix &a)
    {
        int *tmp = (int *)malloc(sizeof(int) * n * n);
        int *ans = (int *)calloc(n * n, sizeof(int));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i * n + j] = a.data[j * n + i];
            }
        }
        
        for (int i = 0, l = 0; i < n; i++) {
            int *p1 = data + i * n;
            int *p2 = tmp;
            
            for (int j = 0; j < n; j++, l++, p2 += n) {
                int *pa = p1;
                int *pb = p2;
                long long sum = 0;
                
                for (int k = 0; k < n; k++, pa++, pb++) {
                    sum += (long long)*pa * *pb;
                    if (sum >= mod2) sum -= mod2;
                }
                
                ans[l] = sum % mod;
            }
        }
        
        for (int i = 0; i < n * n; i++) data[i] = ans[i];
        
        free(tmp);
        free(ans);
    }
    
    const Matrix operator^(long long x) const
    {
        Matrix a = *this;
        Matrix ans(n, m);
        
        ans.identify();
        
        while (x) {
            if (x & 1) ans *= a;
            a *= a;
            x >>= 1;
        }
        
        return ans;
    }
};

int main()
{
    int k, i, j;
    long long n;
    long long b[41];
    long long c[41][41] = {{0}};
    
    scanf("%I64d %d", &n, &k);
    
    Matrix a(k * 2 + 3, k * 2 + 3);
    
    a[k * 2 + 2][k * 2 + 1] = a[k * 2 + 2][k * 2 + 2] = 1;
    
    b[0] = 1;
    
    for (i = 1; i <= k; i++) b[i] = b[i - 1] * 2 % mod;
    
    for (i = 0; i <= k; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    
    for (i = 0; i <= k; i++) {
        for (j = 0; j <= k; j++) {
            a[i][j] = c[i][j];
            a[i][j + k + 1] = c[i][j] * b[i - j] % mod;
        }
        
        a[i + k + 1][i] = 1;
    }
    
    Matrix d = a ^ n;
    
    Vector x(k * 2 + 3);
    
    for (i = 0; i <= k; i++) {
        x[i] = b[i] * 2 % mod;
        x[i + k + 1] = 1;
    }
    
    Vector y = d * x;
    
    printf("%d\n", y[k * 2 + 2]);
    
    return 0;
}