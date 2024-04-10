#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
int a[7][2];
int b[1000][2];
int f[7][1000];
int g[1000];
vector <int> v[7][1000];

bool on(int x1, int y1, int x2, int y2) {
    if ((long long)x1 * y2 != (long long)x2 * y1) return false;
    
    if (x1 > 0 && x2 < 0) return false;
    if (x1 < 0 && x2 > 0) return false;
    if (y1 > 0 && y2 < 0) return false;
    if (y1 < 0 && y2 > 0) return false;
    
    if (x1 == 0) {
        return abs(y1) > abs(y2);
    } else if (y1 == 0) {
        return abs(x1) > abs(x2);
    } else {
        return abs((long long)x1 * y1) > abs((long long)x2 * y2);
    }
}

int dfs(vector <int> &w, int x) {
    int p, i, j;
    
    if (w.size() == 0) return 1;
    if (w.size() > k - __builtin_popcount(x)) return 0;
    
    p = w.back();
    
    for (i = 0; i < k; i++) {
        vector <int> z;
        
        if ((x >> i) & 1) continue;
        
        z = w;
        z.pop_back();
        
        if (f[i][p] == 1) {
            g[p] = 1;
            
            if (dfs(z, x | (1 << i)) == 1) {
                g[p] = 0;
                return 1;
            }
        } else if (v[i][p].size() > 0) {
            for (j = 0; j < v[i][p].size(); j++) {
                if (g[v[i][p][j]] == 0) z.push_back(v[i][p][j]);
            }
            
            sort(z.begin(), z.end());
            z.erase(unique(z.begin(), z.end()), z.end());
            
            g[p] = 1;
            
            if (dfs(z, x | (1 << i)) == 1) {
                g[p] = 0;
                return 1;
            }
        }
        
        g[p] = 0;
    }
    
    return 0;
}

int main() {
    int ans = 0, i, j, l;
    
    scanf("%d %d", &k, &n);
    
    for (i = 0; i < k; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    for (i = 0; i < n; i++) scanf("%d %d", &b[i][0], &b[i][1]);
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            int x1, y1;
            vector <int> z;
            
            x1 = a[i][0] - b[j][0];
            y1 = a[i][1] - b[j][1];
            
            for (l = 0; l < n; l++) {
                int x2, y2;
                
                if (l == j) continue;
                
                x2 = a[i][0] - b[l][0];
                y2 = a[i][1] - b[l][1];
                
                if (on(x1, y1, x2, y2)) z.push_back(l);
            }
            
            if (z.size() == 0) {
                f[i][j] = 1;
            } else if (z.size() < k) {
                v[i][j] = z;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        vector <int> w;
        
        w.push_back(i);
        
        ans += dfs(w, 0);
    }
    
    printf("%d\n", ans);
    
    return 0;
}