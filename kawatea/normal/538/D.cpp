#include <cstdio>
#include <vector>

using namespace std;

char s[50][51];
char c[50][51];
char ans[100][100];

int main()
{
    int n, i, j, k;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s[i][j] == 'o') v.push_back(make_pair(i, j));
        }
    }
    
    for (i = 0; i < n * 2 - 1; i++) {
        for (j = 0; j < n * 2 - 1; j++) {
            ans[i][j] = '.';
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = '.';
        }
    }
    
    for (i = -n + 1; i <= n - 1; i++) {
        for (j = -n + 1; j <= n - 1; j++) {
            for (k = 0; k < v.size(); k++) {
                int x = v[k].first + i;
                int y = v[k].second + j;
                
                if (x < 0 || x >= n || y < 0 || y >= n || s[x][y] != '.') continue;
                
                break;
            }
            
            if (k == v.size()) {
                ans[n + i - 1][n + j - 1] = 'x';
                
                for (k = 0; k < v.size(); k++) {
                    int x = v[k].first + i;
                    int y = v[k].second + j;
                    
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    
                    c[x][y] = 'x';
                }
            }
        }
    }
    
    for (i = 0; i < v.size(); i++) c[v[i].first][v[i].second] = 'o';
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s[i][j] != c[i][j]) {
                puts("NO");
                
                return 0;
            }
        }
    }
    
    ans[n - 1][n - 1] = 'o';
    
    puts("YES");
    
    for (i = 0; i < n * 2 - 1; i++) printf("%s\n", ans[i]);
    
    return 0;
}