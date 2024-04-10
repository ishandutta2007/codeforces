#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long a[200000][2];
int ans[200000];

int main()
{
    int n, m, i;
    vector <pair<long long, pair<int, int> > > v;
    priority_queue <pair<long long, int> > q;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%I64d %I64d", &a[i][0], &a[i][1]);
    
    for (i = 0; i < m; i++) {
        long long x;
        
        scanf("%I64d", &x);
        
        v.push_back(make_pair(x, make_pair(0, i)));
    }
    
    for (i = 0; i < n - 1; i++) v.push_back(make_pair(a[i + 1][0] - a[i][1], make_pair(-1, i)));
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (v[i].second.first == -1) {
            int x = v[i].second.second;
            long long y = a[x + 1][1] - a[x][0];
            
            q.push(make_pair(-y, x));
        } else {
            if (q.empty()) continue;
            
            if (-q.top().first < v[i].first) {
                puts("No");
                
                return 0;
            }
            
            ans[q.top().second] = v[i].second.second + 1;
            
            q.pop();
        }
    }
    
    if (!q.empty()) {
        puts("No");
        
        return 0;
    }
    
    puts("Yes");
    
    for (i = 0; i < n - 1; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}