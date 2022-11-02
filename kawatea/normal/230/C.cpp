#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, ans = 1e9, i, j;
    int a[10000] = {0};
    char s[10001];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        vector <int> v, w;
        
        scanf("%s", s);
        
        for (j = 0; j < m; j++) {
            if (s[j] == '1') v.push_back(j);
        }
        
        for (j = m - 1; j >= 0; j--) {
            if (s[j] == '1') w.push_back(-j);
        }
        
        if (v.size() == 0) {
            puts("-1");
            
            return 0;
        }
        
        for (j = 0; j < m; j++) {
            int c = 1e9;
            vector <int>::iterator it;
            
            it = lower_bound(v.begin(), v.end(), j);
            
            if (it != v.end()) {
                c = min(c, *it - j);
            } else {
                c = min(c, m - j + v[0]);
            }
            
            it = lower_bound(w.begin(), w.end(), -j);
            
            if (it != w.end()) {
                c = min(c, *it + j);
            } else {
                c = min(c, m + j + w[0]);
            }
            
            a[j] += c;
        }
    }
    
    for (i = 0; i < m; i++) ans = min(ans, a[i]);
    
    printf("%d\n", ans);
    
    return 0;
}