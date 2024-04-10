#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int mod = 1000000007;
long long a[10][2];
char s[100001];
char s2[100005];

int get(long long x)
{
    long long ans = 1, y = 10;
    
    while (x) {
        if (x & 1) ans = ans * y % mod;
        
        y = y * y % mod;
        x >>= 1;
    }
    
    return ans;
}

int main()
{
    int n, q, i, j;
    long long ans = 0, sum = 0;
    vector <string> v;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        scanf("%s", s2);
        
        v.push_back((string)s2);
    }
    
    for (i = 0; i < 10; i++) {
        a[i][0] = 1;
        a[i][1] = i;
    }
    
    for (i = q - 1; i >= 0; i--) {
        int x = v[i][0] - '0';
        long long y = 0, z = 0;
        
        for (j = v[i].size() - 1; j >= 3; j--) {
            z += a[v[i][j] - '0'][1] * get(y) % mod;
            y += a[v[i][j] - '0'][0];
            
            if (z >= mod) z -= mod;
            if (y >= mod - 1) y -= mod - 1;
        }
        
        a[x][0] = y;
        a[x][1] = z;
    }
    
    for (i = n - 1; i >= 0; i--) {
        ans += a[s[i] - '0'][1] * get(sum) % mod;
        sum += a[s[i] - '0'][0];
        
        if (ans >= mod) ans -= mod;
        if (sum >= mod - 1) sum -= mod - 1;
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}