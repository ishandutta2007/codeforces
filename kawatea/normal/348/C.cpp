#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];
int c[100000];
int d[100000][200];
long long sum[100000];
long long sum2[100000];
long long sum3[100000];
vector <int> v[100000];
vector <int> w;

int main()
{
    int n, m, q, i, j, k;
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        for (j = 0; j < x; j++) {
            int y;
            
            scanf("%d", &y);
            
            y--;
            
            sum[i] += a[y];
            v[i].push_back(y);
        }
        
        if (x >= 500) {
            c[i] = w.size();
            w.push_back(i);
        }
    }
    
    for (i = 0; i < n; i++) b[i] = -1;
    
    for (i = 0; i < w.size(); i++) {
        int x = w[i];
        
        for (j = 0; j < v[x].size(); j++) b[v[x][j]] = i;
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < v[j].size(); k++) {
                if (b[v[j][k]] == i) d[j][i]++;
            }
        }
    }
    
    for (i = 0; i < q; i++) {
        char s[2];
        
        scanf("%s", s);
        
        if (s[0] == '?') {
            int x;
            long long ans;
            
            scanf("%d", &x);
            
            x--;
            
            ans = sum[x];
            
            for (j = 0; j < w.size(); j++) ans += sum2[j] * d[x][j];
            
            if (v[x].size() < 500) {
                for (j = 0; j < v[x].size(); j++) ans += sum3[v[x][j]];
            }
            
            printf("%I64d\n", ans);
        } else {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            x--;
            
            if (v[x].size() >= 500) {
                sum2[c[x]] += y;
            } else {
                for (j = 0; j < v[x].size(); j++) sum3[v[x][j]] += y;
                for (j = 0; j < w.size(); j++) sum[w[j]] += (long long)y * d[x][j];
            }
        }
    }
    
    return 0;
}