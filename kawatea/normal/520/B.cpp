#include <cstdio>
#include <queue>

using namespace std;

int a[20000];

int main()
{
    int n, m, i;
    queue <int> q;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < 20000; i++) a[i] = -1;
    
    a[n] = 0;
    q.push(n);
    
    while (1) {
        int x = q.front();
        
        q.pop();
        
        if (x == m) {
            printf("%d\n", a[x]);
            
            return 0;
        }
        
        if (x > 0 && a[x - 1] == -1) {
            a[x - 1] = a[x] + 1;
            q.push(x - 1);
        }
        
        if (x <= m && a[x * 2] == -1) {
            a[x * 2] = a[x] + 1;
            q.push(x * 2);
        }
    }
    
    return 0;
}