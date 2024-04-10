#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

char s[1000001];

int main()
{
    int n, sum = 0, sum2 = 0, i;
    priority_queue <pair<int, int> > q;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        sum += x;
        s[i] = 'A';
        
        q.push(make_pair(x, i));
    }
    
    while (!q.empty() && sum > sum2 + 500) {
        int x = q.top().first;
        int y = q.top().second;
        
        q.pop();
        
        sum -= x;
        sum2 += 1000 - x;
        s[y] = 'G';
    }
    
    if (abs(sum - sum2) <= 500) {
        s[n] = '\0';
        
        printf("%s\n", s);
    } else {
        puts("-1");
    }
    
    return 0;
}