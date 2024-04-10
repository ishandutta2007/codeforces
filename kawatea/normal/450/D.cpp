#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a[100000];
long long d[100000];
vector <pair<int, int> > v[100000];

int main()
{
    int n, m, k, ans = 0, i;
    priority_queue <pair<long long, int> > q;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) d[i] = 1e18;
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
    }
    
    for (i = 0; i < k; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        
        d[x] = min(d[x], (long long)y);
        q.push(make_pair(-y, -x));
    }
    
    d[0] = 0;
    q.push(make_pair(0, 0));
    
    while (!q.empty()) {
        long long x = -q.top().first;
        int y = q.top().second;
        
        q.pop();
        
        if (y < 0) {
            y = -y;
            
            if (a[y] == 1) ans++;
        }
        
        if (a[y] == 1) continue;
        
        a[y] = 1;
        
        for (i = 0; i < v[y].size(); i++) {
            if (d[v[y][i].first] >= x + v[y][i].second) {
                d[v[y][i].first] = x + v[y][i].second;
                q.push(make_pair(-d[v[y][i].first], v[y][i].first));
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}