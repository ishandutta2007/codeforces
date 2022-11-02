#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[500][500];
int b[500][500];
int c[500][501];
int d[500][501];
int e[1001];

int main()
{
    int n, m, r, sum = 0, ans = 0, i, j, k;
    long long num = 0;
    vector <pair<int, int> > v;
    
    scanf("%d %d %d", &n, &m, &r);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        int x = -1, y = -1;
        
        for (j = 0; j < m; j++) {
            if ((r - i) * (r - i) + (r - j) * (r - j) <= r * r) {
                sum += a[i][j];
                
                if (x == -1) x = j;
                y = j;
            }
        }
        
        if (x != -1) v.push_back(make_pair(x, y));
    }
    
    for (i = r; i < n - r; i++) {
        int sum2;
        
        if (i > r) {
            for (j = 0; j <= r * 2; j++) {
                sum -= a[v[j].first + i - r - 1][j];
                sum += a[v[j].second + i - r][j];
            }
        }
        
        sum2 = sum;
        
        for (j = r; j < m - r; j++) {
            b[i][j] = sum2;
            
            if (j < m - r - 1) {
                for (k = 0; k <= r * 2; k++) {
                    sum2 -= a[i - r + k][v[k].first + j - r];
                    sum2 += a[i - r + k][v[k].second + j - r + 1];
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = m - 1; j >= 0; j--) {
            c[i][j] = max(b[i][j], c[i][j + 1]);
            
            if (c[i][j] == c[i][j + 1]) d[i][j] += d[i][j + 1];
            if (c[i][j] == b[i][j]) d[i][j]++;
        }
    }
    
    for (i = 0; i <= n; i++) {
        if (i >= r * 2 + 1) {
            e[n - i] = 1;
            e[n + i] = 0;
        } else {
            int x = 0;
            
            for (j = 0; i + j <= r * 2; j++) {
                x = max(x, v[j].second - v[i + j].first + 1);
            }
            
            e[n - i] = e[n + i] = x;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (b[i][j] == 0) continue;
            
            for (k = 0; k < n; k++) {
                if (j + e[k - i + n] >= m) continue;
                if (c[k][j + e[k - i + n]] == 0) continue;
                
                if (b[i][j] + c[k][j + e[k - i + n]] > ans) {
                    ans = b[i][j] + c[k][j + e[k - i + n]];
                    num = d[k][j + e[k - i + n]];
                } else if (b[i][j] + c[k][j + e[k - i + n]] == ans) {
                    num += d[k][j + e[k - i + n]];
                }
            }
        }
    }
    
    printf("%d %I64d\n", ans, num);
    
    return 0;
}