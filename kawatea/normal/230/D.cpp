#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <pair<int, int> > e[100000];
vector <int> v[100000];
int f[100000];

int main()
{
    int n, m, i, j;
    priority_queue <pair<int, int> > q;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        e[x].push_back(make_pair(y, z));
        e[y].push_back(make_pair(x, z));
    }
    
    for (i = 0; i < n; i++) {
        int k;
        
        scanf("%d", &k);
        
        for (j = 0; j < k; j++) {
            int t;
            
            scanf("%d", &t);
            
            v[i].push_back(t);
        }
    }
    
    q.push(make_pair(0, 0));
    
    while (!q.empty()) {
        int c = -q.top().first;
        int x = q.top().second;
        vector <int>::iterator it;
        
        q.pop();
        
        if (f[x] == 1) continue;
        
        f[x] = 1;
        
        if (x == n - 1) {
            printf("%d\n", c);
            
            return 0;
        }
        
        it = lower_bound(v[x].begin(), v[x].end(), c);
        
        while (it != v[x].end()) {
            if (*it != c) break;
            
            it++;
            c++;
        }
        
        for (i = 0; i < e[x].size(); i++) {
            if (f[e[x][i].first] == 1) continue;
            
            q.push(make_pair(-c - e[x][i].second, e[x][i].first));
        }
    }
    
    puts("-1");
    
    return 0;
}