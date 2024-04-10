#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, m, k, ans = 0, i, j;
    vector <int> v[100000];
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[x - 1].push_back(i);
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < v[i].size(); j++) {
            int l = j - 1, r = v[i].size(), m = (l + r) / 2;
            
            while (r - l > 1) {
                if (v[i][m] - v[i][j] - m + j <= k) {
                    l = m;
                    m = (l + r) / 2;
                } else {
                    r = m;
                    m = (l + r) / 2;
                }
            }
            
            ans = max(ans, l - j + 1);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}