#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int m, k, p, sum = 0, i;
    int a[1000], b[1000];
    priority_queue <int> q;
    
    scanf("%d %d", &m, &k);
    
    for (i = 0; i < m; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    
    p = b[0];
    
    q.push(b[0]);
    
    for (i = 0; i < m; i++) {
        while (p < a[i]) {
            p += q.top();
            
            sum += k;
        }
        
        p -= a[i];
        sum += a[i];
        
        if (i < m - 1) {
            p += b[i + 1];
            q.push(b[i + 1]);
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}