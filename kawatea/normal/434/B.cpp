#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int a[1002][1002];
int b[1002][1002];
int c[1002][1002];
int d[1002];
int ans[1000];
vector <pair<int, pair<int, int> > > v;

int get(int x, int y)
{
    int ans = 0;
    stack <pair<int, int> > s;
    
    for (x++; x <= y; x++) {
        if (s.empty() || s.top().first < d[x]) {
            s.push(make_pair(d[x], x));
        } else if (s.top().first > d[x]) {
            int p = x;
            
            while (!s.empty() && s.top().first >= d[x]) {
                ans = max(ans, s.top().first * (x - s.top().second));
                p = s.top().second;
                s.pop();
            }
            
            s.push(make_pair(d[x], p));
        }
    }
    
    return ans;
}

int main()
{
    int n, m, q, i, j, k, l;
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i + 1][j + 1]);
        }
    }
    
    for (i = 0; i < q; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        v.push_back(make_pair(x, make_pair(y, z)));
    }
    
    n = max(n, m);
    
    for (i = 0; i < 4; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                b[j][k] = a[j][k];
            }
        }
        
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                if (b[j][k] == 0) {
                    c[j][k] = 0;
                } else {
                    c[j][k] = c[j - 1][k] + 1;
                }
            }
        }
        
        for (j = 0; j < q; j++) {
            int x = v[j].second.first;
            int y = v[j].second.second;
            
            if (v[j].first == 1) {
                b[x][y] = 1 - b[x][y];
                
                if (b[x][y] == 0) {
                    c[x][y] = 0;
                } else {
                    c[x][y] = c[x - 1][y] + 1;
                }
                
                for (k = x + 1; k <= n; k++) {
                    if (b[k][y] == 0) break;
                    
                    c[k][y] = c[k - 1][y] + 1;
                }
            } else {
                if (b[x][y] == 0) continue;
                
                d[y] = c[x][y];
                
                for (k = y - 1; k >= 1; k--) {
                    d[k] = min(d[k + 1], c[x][k]);
                    
                    if (d[k] == 0) break;
                }
                
                for (l = y + 1; l <= n; l++) {
                    d[l] = min(d[l - 1], c[x][l]);
                    
                    if (d[l] == 0) break;
                }
                
                ans[j] = max(ans[j], get(k, l));
            }
        }
        
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                b[j][k] = a[n - k + 1][j];
            }
        }
        
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                a[j][k] = b[j][k];
            }
        }
        
        for (j = 0; j < q; j++) {
            int x = v[j].second.first;
            int y = v[j].second.second;
            
            v[j].second.first = y;
            v[j].second.second = n - x + 1;
        }
    }
    
    for (i = 0; i< q; i++) {
        if (v[i].first == 2) printf("%d\n", ans[i]);
    }
    
    return 0;
}