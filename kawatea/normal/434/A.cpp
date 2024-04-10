#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
vector <int> v[100001];

int main()
{
    int n, m, i, j;
    long long ans = 0, tmp = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m - 1; i++) ans += abs(a[i + 1] - a[i]);
    
    for (i = 0; i < m; i++) {
        if (i > 0 && a[i] != a[i - 1]) v[a[i]].push_back(a[i - 1]);
        if (i < m - 1 && a[i] != a[i + 1]) v[a[i]].push_back(a[i + 1]);
    }
    
    for (i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
    
    for (i = 1; i <= n; i++) {
        int x;
        long long sum1 = 0, sum2 = 0;
        
        if (v[i].size() == 0) continue;
        
        x = v[i][v[i].size() / 2];
        
        for (j = 0; j < v[i].size(); j++) {
            sum1 += abs(v[i][j] - i);
            sum2 += abs(v[i][j] - x);
        }
        
        tmp = max(tmp, sum1 - sum2);
    }
    
    printf("%I64d\n", ans - tmp);
    
    return 0;
}