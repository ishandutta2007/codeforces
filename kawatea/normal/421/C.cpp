#include <cstdio>
#include <vector>

using namespace std;

int a[100000];
int b[100000];
long long sum[200002];
long long sum2[200002];
vector <pair<int, int> > v[100000];

int main()
{
    int n, m, i, j;
    vector <int> ans;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) b[i] = -1;
    
    for (i = 0; i < m; i++) {
        int x;
        char s[2];
        
        scanf("%s %d", s, &x);
        
        x--;
        
        a[x]++;
        
        if (s[0] == '+') {
            b[x] = i;
        } else {
            v[x].push_back(make_pair(b[x], i));
            
            b[x] = -1;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] >= 0)v[i].push_back(make_pair(b[i], m));
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i].size(); j++) {
            if (v[i][j].first == -1) {
                sum[0]++;
            } else {
                sum[v[i][j].first * 2 + 1]++;
            }
            
            sum[v[i][j].second * 2 + 1]--;
        }
    }
    
    for (i = 1; i < 2 * m + 2; i++) sum[i] += sum[i - 1];
    sum2[0] = sum[0];
    for (i = 1; i < 2 * m + 2; i++) sum2[i] = sum2[i - 1] + sum[i];
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            ans.push_back(i + 1);
        } else {
            if (v[i][0].first >= 0) {
                if (sum2[v[i][0].first * 2] > 0) continue;
            }
            
            if (v[i].back().second < m) {
                if (sum2[2 * m + 1] - sum2[v[i].back().second * 2] > 0) continue;
            }
            
            for (j = 0; j < v[i].size() - 1; j++) {
                int x = v[i][j].second * 2;
                int y = v[i][j + 1].first * 2;
                
                if (sum2[y] - sum2[x] > 0) break;
            }
            
            if (j < v[i].size() - 1) continue;
            
            ans.push_back(i + 1);
        }
    }
    
    printf("%d\n", ans.size());
    
    for (i = 0; i < ans.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}