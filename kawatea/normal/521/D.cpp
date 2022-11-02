#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000][3];
int c[100000][2];
vector <pair<int, int> > v[100000];

int main()
{
    int k, n, m, i, j;
    vector <pair<double, int> > w;
    vector <pair<int, int> > z;
    
    scanf("%d %d %d", &k, &n, &m);
    
    for (i = 0; i < k; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
        
        b[i][1]--;
    }
    
    for (i = 0; i < k; i++) c[i][0] = -1;
    
    for (i = 0; i < n; i++) {
        if (b[i][0] == 1) {
            int x = b[i][1], y = b[i][2];
            
            if (c[x][0] < y) {
                c[x][0] = y;
                c[x][1] = i + 1;
            }
        } else if (b[i][0] == 2) {
            int x = b[i][1], y = b[i][2];
            
            v[x].push_back(make_pair(y, i + 1));
        } else {
            w.push_back(make_pair(b[i][2], i + 1));
        }
    }
    
    for (i = 0; i < k; i++) {
        double sum = a[i];
        
        if (c[i][0] > a[i]) v[i].push_back(make_pair(c[i][0] - a[i], c[i][1]));
        
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        
        for (j = 0; j < v[i].size(); j++) {
            w.push_back(make_pair((sum + v[i][j].first) / sum, v[i][j].second));
            sum += v[i][j].first;
        }
    }
    
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    for (i = 0; i < w.size() && i < m; i++) z.push_back(make_pair(b[w[i].second - 1][0], w[i].second));
    
    sort(z.begin(), z.end());
    
    printf("%d\n", z.size());
    
    for (i = 0; i < z.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", z[i].second);
    }
    
    puts("");
    
    return 0;
}