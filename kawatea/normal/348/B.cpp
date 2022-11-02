#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
long long b[100000];
long long d[100000];
vector <int> v[100000];

long long gcd(long long a, long long b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

long long dfs(int x, int y)
{
    int c = 0, i;
    long long m = 1e18, p = 1, sum = 0, ans = 0;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] != y) {
            ans += dfs(v[x][i], x);
            
            m = min(m, b[v[x][i]]);
            c++;
            sum += b[v[x][i]];
            
            if (p != -1) {
                long long np = lcm(p, d[v[x][i]]);
                
                if (np < p || np % d[v[x][i]] != 0) {
                    p = -1;
                } else {
                    p = np;
                }
            }
        }
    }
    
    if (c == 0) {
        b[x] = a[x];
        d[x] = 1;
        
        return 0;
    }
    
    if (p * c < p || p * c % c != 0) p = -1;
    
    if (p == -1) {
        b[x] = 0;
        d[x] = 1;
        
        return ans + sum;
    }
    
    m = m / p * p;
    
    b[x] = m * c;
    d[x] = p * c;
    
    ans += sum - m * c;
    
    return ans;
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    
    printf("%I64d\n", dfs(0, -1));
    
    return 0;
}