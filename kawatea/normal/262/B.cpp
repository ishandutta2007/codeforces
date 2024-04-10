#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n, k, sum = 0, i;
    priority_queue <int> q1, q2;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x < 0) {
            q1.push(-x);
        } else {
            q2.push(-x);
        }
    }
    
    while (k > 0 && !q1.empty()) {
        int x = q1.top();
        
        q1.pop();
        
        q2.push(-x);
        
        k--;
    }
    
    k %= 2;
    
    if (k == 1) {
        int x = q2.top();
        
        q2.pop();
        
        q1.push(-x);
    }
    
    while (!q1.empty()) {
        sum += -q1.top();
        
        q1.pop();
    }
    
    while (!q2.empty()) {
        sum += -q2.top();
        
        q2.pop();
    }
    
    printf("%d\n", sum);
    
    return 0;
}