#include <cstdio>
#include <map>

using namespace std;

map <long long, long long> mp[64];

long long dfs(int x, long long y)
{
    long long tmp;
    
    if (mp[x].count(y)) return mp[x][y];
    
    if (x == 0) {
        if (y == 1) {
            return mp[x][y] = 1;
        } else {
            return mp[x][y] = 0;
        }
    }
    
    tmp = dfs(x - 1, y);
    
    if (y % 2 == 0) tmp += dfs(x - 1, y / 2);
    
    return mp[x][y] = tmp;
}

int main()
{
    long long n, t, m, sum = 0, i, j;
    
    scanf("%I64d %I64d", &n, &t);
    
    n++;
    
    m = n;
    
    for (i = 0; m > 0; i++) m >>= 1;
    
    for (j = 0; j < i - 1; j++) sum += dfs(j, t);
    
    n -= (1LL << (i - 1)) - 1;
    
    if (t == 1) sum--;
    
    while (n) {
        m = n;
        
        for (i = 0; m > 0; i++) m >>= 1;
        
        sum += dfs(i - 1, t);
        
        n -= (1LL << (i - 1));
        
        if (t % 2 != 0) break;
        
        t /= 2;
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}