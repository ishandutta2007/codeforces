#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[50][51];
char t[50][51];

void swap(int n, int m, char s[50][51]) {
    int i, j;
    char tmp[50][51];
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'L') {
                tmp[j][i] = 'U';
            } else if (s[i][j] == 'R') {
                tmp[j][i] = 'D';
            } else if (s[i][j] == 'U') {
                tmp[j][i] = 'L';
            } else {
                tmp[j][i] = 'R';
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            s[i][j] = tmp[i][j];
        }
    }
}

void change(int x, int y, char s[50][51]) {
    if (s[x][y] == 'U') {
        s[x][y] = s[x + 1][y] = 'L';
        s[x][y + 1] = s[x + 1][y + 1] = 'R';
    } else {
        s[x][y] = s[x][y + 1] = 'U';
        s[x + 1][y] = s[x + 1][y + 1] = 'D';
    }
}

int main() {
    int n, m, f = 0, i, j, k;
    vector <pair<int, int> > ans1, ans2;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    for (i = 0; i < n; i++) scanf("%s", t[i]);
    
    if (n % 2 == 1) {
        f = 1;
        
        swap(n, m, s);
        swap(n, m, t);
        swap(n, m);
    }
    
    for (i = 0; i < n; i += 2) {
        for (j = 0; j < m; j++) {
            int x = i, y = j;
            vector <pair<int, int> > v;
            
            if (s[i][j] == 'U') continue;
            
            v.push_back(make_pair(x, y));
            
            while (1) {
                if (s[x][y] == 'L') {
                    x++;
                    if (s[x][y] == 'L') break;
                } else {
                    y++;
                    if (s[x][y] == 'U') break;
                }
                
                v.push_back(make_pair(x, y));
            }
            
            for (k = v.size() - 1; k >= 0; k--) {
                ans1.push_back(v[k]);
                change(v[k].first, v[k].second, s);
            }
        }
    }
    
    for (i = 0; i < n; i += 2) {
        for (j = 0; j < m; j++) {
            int x = i, y = j;
            vector <pair<int, int> > v;
            
            if (t[i][j] == 'U') continue;
            
            v.push_back(make_pair(x, y));
            
            while (1) {
                if (t[x][y] == 'L') {
                    x++;
                    if (t[x][y] == 'L') break;
                } else {
                    y++;
                    if (t[x][y] == 'U') break;
                }
                
                v.push_back(make_pair(x, y));
            }
            
            for (k = v.size() - 1; k >= 0; k--) {
                ans2.push_back(v[k]);
                change(v[k].first, v[k].second, t);
            }
        }
    }
    
    reverse(ans2.begin(), ans2.end());
    
    if (f == 1) {
        for (i = 0; i < ans1.size(); i++) swap(ans1[i].first, ans1[i].second);
        for (i = 0; i < ans2.size(); i++) swap(ans2[i].first, ans2[i].second);
    }
    
    printf("%d\n", ans1.size() + ans2.size());
    for (i = 0; i < ans1.size(); i++) printf("%d %d\n", ans1[i].first + 1, ans1[i].second + 1);
    for (i = 0; i < ans2.size(); i++) printf("%d %d\n", ans2[i].first + 1, ans2[i].second + 1);
    
    return 0;
}