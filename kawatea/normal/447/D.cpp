#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[1000][1000];
long long b[1000001];
long long c[1000001];

int main()
{
    int n, m, k, p, i, j;
    long long ans = -1e18;
    priority_queue <long long> q1, q2;
    
    scanf("%d %d %d %d", &n, &m, &k, &p);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        long long sum = 0;
        
        for (j = 0; j < m; j++) sum += a[i][j];
        
        q1.push(sum);
    }
    
    for (i = 0; i < k; i++) {
        long long x = q1.top();
        
        q1.pop();
        
        b[i + 1] = b[i] + x;
        
        q1.push(x - p * m);
    }
    
    for (i = 0; i < m; i++) {
        long long sum = 0;
        
        for (j = 0; j < n; j++) sum += a[j][i];
        
        q2.push(sum);
    }
    
    for (i = 0; i < k; i++) {
        long long x = q2.top();
        
        q2.pop();
        
        c[i + 1] = c[i] + x;
        
        q2.push(x - p * n);
    }
    
    for (i = 0; i <= k; i++) ans = max(ans, b[i] + c[k - i] - (long long)p * i * (k - i));
    
    printf("%I64d\n", ans);
    
    return 0;
}