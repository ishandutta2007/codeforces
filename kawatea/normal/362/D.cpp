#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int par[100000];
int a[100000];
long long b[100000];

int find(int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int n, m, p, q, c = 0, x1 = -1, y1, i;
    vector <pair<int, int> > v;
    priority_queue <pair<long long, int> > que;
    
    scanf("%d %d %d %d", &n, &m, &p, &q);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        if (i == 0) {
            x1 = x;
            y1 = y;
        }
        
        x--;
        y--;
        
        unite(x, y);
        v.push_back(make_pair(x, z));
    }
    
    for (i = 0; i < n; i++) a[i] = -1;
    
    for (i = 0; i < n; i++) {
        if (a[find(i)] == -1) {
            a[find(i)] = i;
            c++;
        }
    }
    
    for (i = 0; i < v.size(); i++) {
        b[find(v[i].first)] += v[i].second;
        b[find(v[i].first)] = min(b[find(v[i].first)], (long long)1e9);
    }
    
    if (q > c || c - p > q || (m == 0 && p > 0 && q == c)) {
        puts("NO");
        
        return 0;
    }
    
    puts("YES");
    
    for (i = 0; i < n; i++) {
        if (a[i] != -1) que.push(make_pair(-b[i], i));
    }
    
    for (i = 0; i < p; i++) {
        if (que.size() == q) {
            printf("%d %d\n", x1, y1);
        } else {
            int x, y;
            
            x = que.top().second;
            que.pop();
            y = que.top().second;
            que.pop();
            
            if (x1 == -1) {
                x1 = a[x] + 1;
                y1 = a[y] + 1;
            }
            
            printf("%d %d\n", a[x] + 1, a[y] + 1);
            
            b[x] += b[x] + b[y] * 2 + 1;
            b[x] = min(b[x], (long long)1e9);
            que.push(make_pair(-b[x], x));
        }
    }
    
    return 0;
}