#include <cstdio>
#include <algorithm>

using namespace std;

const int num = 600;
const int mod = 1000000009;
int a[300000];
int b[1000];
int c[1000][2];
int d[300001];
int f[300001];
int sum[300001];
int sum2[300001];

long long get(int x)
{
    int y = x / num, z = x % num, c1, c2, i;
    long long ans = 0;
    
    if (x == 0) return 0;
    
    for (i = 0; i < y; i++) ans += b[i];
    
    c1 = c[y][0];
    c2 = c[y][1];
    
    for (i = 0; i < z; i++) {
        int nc;
        
        ans += c1;
        ans += a[x - z + i];
        
        nc = c1 + c2;
        if (nc >= mod) nc -= mod;
        c2 = c1;
        c1 = nc;
    }
    
    return ans;
}

int main()
{
    int n, m, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        b[i / num] += a[i];
        if (b[i / num] >= mod) b[i / num] -= mod;
    }
    
    for (i = 0; i <= n; i++) d[i] = i % num;
    
    f[1] = f[2] = 1;
    
    for (i = 3; i <= 300000; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] >= mod) f[i] -= mod;
    }
    
    for (i = 0; i < 300000; i++) {
        sum[i + 1] = sum[i] + f[i + 1];
        if (sum[i + 1] >= mod) sum[i + 1] -= mod;
    }
    
    for (i = num; i <= 300000; i++) {
        sum2[i] = sum[i] - sum[i - num];
        if (sum2[i] < 0) sum2[i] += mod;
    }
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        if (x == 1) {
            int p, q;
            
            y--;
            
            p = y / num;
            q = z / num;
            
            if (d[y] == 0) p--;
            
            for (j = p + 1; j < q; j++) {
                int s = j * num - y;
                int t = (j + 1) * num - y;
                
                b[j] += sum2[t];
                if (b[j] >= mod) b[j] -= mod;
                
                c[j][0] += f[s + 1];
                c[j][1] += f[s];
                
                if (c[j][0] >= mod) c[j][0] -= mod;
                if (c[j][1] >= mod) c[j][1] -= mod;
            }
            
            if (p == q) {
                long long sum = 0;
                
                for (j = y; j < z; j++) {
                    a[j] += f[j - y + 1];
                    sum += f[j - y + 1];
                    
                    if (a[j] >= mod) a[j] -= mod;
                }
                
                b[p] += sum % mod;
                if (b[p] >= mod) b[p] -= mod;
            } else {
                int r = d[y];
                long long sum = 0;
                
                if (r > 0) {
                    for (j = r; j < num; j++) {
                        a[y + j - r] += f[j - r + 1];
                        sum += f[j - r + 1];
                        
                        if (a[y + j - r] >= mod) a[y + j - r] -= mod;
                    }
                    
                    b[p] += sum % mod;
                    if (b[p] >= mod) b[p] -= mod;
                }
                
                r = d[z];
                sum = 0;
                
                for (j = 0; j < r; j++) {
                    a[z - r + j] += f[z - y - r + j + 1];
                    sum += f[z - y - r + j + 1];
                    
                    if (a[z - r + j] >= mod) a[z - r + j] -= mod;
                }
                
                b[q] += sum % mod;
                if (b[q] >= mod) b[q] -= mod;
            }
        } else {
            printf("%I64d\n", ((get(z) - get(y - 1)) % mod + mod) % mod);
        }
    }
    
    return 0;
}