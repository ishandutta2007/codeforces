#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int a[100000];
vector <int> v[100000];
vector <int> w;
set <pair<int, int> > s[100000];

int main()
{
    int n, m, i, j, k;
    queue <int> q;
    set <pair<int, int> >::iterator it;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int x;
            
            scanf("%d", &x);
            
            v[i].push_back(x);
            
            if (x != -1) s[i].insert(make_pair(x, j));
        }
    }
    
    for (i = 0; i < n; i++) {
        int x;
        
        if (s[i].empty()) continue;
        
        x = s[i].begin()->first;
        
        for (j = 0; j < m; j++) {
            if (v[i][j] == -1) continue;
            
            if (v[i][j] != x) a[j]++;
        }
    }
    
    for (i = 0; i < m; i++) {
        if (a[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int x = q.front();
        
        q.pop();
        
        w.push_back(x);
        
        for (i = 0; i < n; i++) {
            int y;
            
            if (v[i][x] == -1) continue;
            
            s[i].erase(make_pair(v[i][x], x));
            
            if (s[i].empty()) continue;
            
            y = s[i].begin()->first;
            
            if (y == v[i][x]) continue;
            
            for (it = s[i].begin(); it != s[i].end(); it++) {
                if (it->first != y) break;
                
                a[it->second]--;
                
                if (a[it->second] == 0) q.push(it->second);
            }
        }
    }
    
    if (w.size() < m) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < m; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w[i] + 1);
    }
    
    puts("");
    
    return 0;
}