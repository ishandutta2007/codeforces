#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];
int d[301];
vector <int> v[100001];

int main()
{
    int n, m, s, e, ans = 0, i, j;
    
    scanf("%d %d %d %d", &n, &m, &s, &e);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < m; i++) v[b[i]].push_back(i);
    
    for (i = 0; i <= 300; i++) d[i] = 1e9;
    d[0] = -1;
    
    for (i = 0; i < n; i++) {
        if (v[a[i]].size() == 0) continue;
        
        for (j = 299; j >= 0; j--) {
            int x = upper_bound(v[a[i]].begin(), v[a[i]].end(), d[j]) - v[a[i]].begin();
            
            if (x == v[a[i]].size()) continue;
            
            d[j + 1] = min(d[j + 1], v[a[i]][x]);
            
            if ((j + 1) * e + i + 1 + v[a[i]][x] + 1 <= s) ans = max(ans, j + 1);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}