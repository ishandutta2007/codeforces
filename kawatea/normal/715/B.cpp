#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, l, s, t;
int a[10000][3];
int b[10000];
int p[1000][2];
long long d[1000];
vector <pair<int, int> > v[1000];

long long calc(void) {
    int i;
    priority_queue<pair<long long, int> > q;
    
    for (i = 0; i < n; i++) d[i] = 1e18;
    
    d[s] = 0;
    q.push(make_pair(0, s));
    
    while (!q.empty()) {
        int x = q.top().second;
        long long y = -q.top().first;
        
        q.pop();
        
        if (x == t) return y;
        
        if (d[x] != y) continue;
        
        for (i = 0; i < v[x].size(); i++) {
            int nx = a[v[x][i].first][v[x][i].second];
            long long ny = y + a[v[x][i].first][2];
            
            if (d[nx] > ny) {
                p[nx][0] = x;
                p[nx][1] = i;
                d[nx] = ny;
                q.push(make_pair(-ny, nx));
            }
        }
    }
    
    return 1e18;
}

int main() {
    int l2, r2, m2, i;
    
    scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = z;
        
        if (z == 0) b[i] = 1;
        
        v[x].push_back(make_pair(i, 1));
        v[y].push_back(make_pair(i, 0));
    }
    
    for (i = 0; i < m; i++) {
        if (b[i] == 1) a[i][2] = 1;
    }
    
    if (calc() > l) {
        puts("NO");
        
        return 0;
    }
    
    for (i = 0; i < m; i++) {
        if (b[i] == 1) a[i][2] = 1e9 + 1;
    }
    
    if (calc() < l) {
        puts("NO");
        
        return 0;
    }
    
    l2 = 1, r2 = 1e9 + 1, m2 = (l2 + r2) / 2;
    
    while (r2 - l2 > 1) {
        for (i = 0; i < m; i++) {
            if (b[i] == 1) a[i][2] = m2;
        }
        
        if (calc() <= l) {
            l2 = m2;
            m2 = (l2 + r2) / 2;
        } else {
            r2 = m2;
            m2 = (l2 + r2) / 2;
        }
    }
    
    for (i = 0; i < m; i++) {
        if (b[i] == 1) a[i][2] = l2;
    }
    
    while (1) {
        int x = t;
        long long c = calc();
        
        if (c == l) break;
        
        while (1) {
            int nx = p[x][0];
            int ny = p[x][1];
            
            if (b[v[nx][ny].first] == 1 && a[v[nx][ny].first][2] == l2) {
                a[v[nx][ny].first][2] += l - c;
                break;
            }
            
            x = nx;
        }
    }
    
    puts("YES");
    for (i = 0; i < m; i++) printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
    
    return 0;
}