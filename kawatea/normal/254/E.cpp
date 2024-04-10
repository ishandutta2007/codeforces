#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int dp[401][401];
int p[401][401];

int main()
{
    int n, v, m, s, t, ans = -1, i, j, k;
    int a[400];
    vector <pair<int, int> > w[400];
    vector <int> d;
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d %d", &n, &v);
    
    for (i = 0; i < n; i++) fscanf(fp, "%d", &a[i]);
    
    fscanf(fp, "%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        fscanf(fp, "%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        for (j = x; j <= y; j++) w[j].push_back(make_pair(z, i + 1));
    }
    
    fclose(fp);
    
    for (i = 0; i < n; i++) sort(w[i].begin(), w[i].end());
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= 400; j++) {
            dp[i][j] = -1;
        }
    }
    
    dp[0][0] = 0;
    p[0][0] = -1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= 400; j++) {
            int x;
            
            if (dp[i][j] == -1) continue;
            
            x = j + a[i] - v;
            
            if (x < 0) continue;
            
            if (dp[i + 1][min(x, a[i])] < dp[i][j]) {
                dp[i + 1][min(x, a[i])] = dp[i][j];
                p[i + 1][min(x, a[i])] = j;
            }
            
            for (k = 0; k < w[i].size(); k++) {
                x -= w[i][k].first;
                
                if (x < 0) break;
                
                if (dp[i + 1][min(x, a[i])] < dp[i][j] + k + 1) {
                    dp[i + 1][min(x, a[i])] = dp[i][j] + k + 1;
                    p[i + 1][min(x, a[i])] = j;
                }
            }
        }
    }
    
    for (i = 0; i <= 400; i++) {
        if (dp[n][i] > ans) {
            ans = dp[n][i];
            s = n;
            t = i;
        }
    }
    
    while (1) {
        int ns = s - 1;
        int nt = p[s][t];
        
        if (ns < 0) break;
        
        d.push_back(dp[s][t] - dp[ns][nt]);
        
        s = ns;
        t = nt;
    }
    
    reverse(d.begin(), d.end());
    
    fp = fopen("output.txt", "w");
    
    fprintf(fp, "%d\n", ans);
    
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d", d[i]);
        
        for (j = 0; j < d[i]; j++) fprintf(fp, " %d", w[i][j].second);
        
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    
    return 0;
}