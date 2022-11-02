#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <pair<int, pair<int, pair<int, int> > > > v[200000];
long long a[200000];
int b[200000];
long long c[200000];

int main()
{
    int n, m, i;
    vector <pair<int, int> > w;
    priority_queue <pair<long long, int> > q;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        a[x] += z;
        a[y] += z;
        
        v[x].push_back(make_pair(y, make_pair(z, make_pair(i, 0))));
        v[y].push_back(make_pair(x, make_pair(z, make_pair(i, 1))));
    }
    
    for (i = 0; i < v[0].size(); i++) {
        c[v[0][i].first] = v[0][i].second.first;
        q.push(make_pair(v[0][i].second.first - a[v[0][i].first] / 2, v[0][i].first));
        
        w.push_back(make_pair(v[0][i].second.second.first, v[0][i].second.second.second));
    }
    
    b[0] = 1;
    
    while (!q.empty()) {
        int x = q.top().second;
        
        q.pop();
        
        if (x == n - 1) continue;
        
        if (b[x] == 1) continue;
        
        b[x] = 1;
        
        for (i = 0; i < v[x].size(); i++) {
            if (b[v[x][i].first] == 1) continue;
            
            c[v[x][i].first] += v[x][i].second.first;
            q.push(make_pair(c[v[x][i].first] - a[v[x][i].first] / 2, v[x][i].first));
            
            w.push_back(make_pair(v[x][i].second.second.first, v[x][i].second.second.second));
        }
    }
    
    sort(w.begin(), w.end());
    
    for (i = 0; i < w.size(); i++) printf("%d\n", w[i].second);
    
    return 0;
}