#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long sum[200001];

int main()
{
    int n, q, i;
    long long ans = 0;
    vector <long long> v, w;
    
    scanf("%d %d", &n, &q);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    for (i = 0; i < q; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        sum[x - 1]++;
        sum[y]--;
    }
    
    for (i = 1; i <= n; i++) sum[i] += sum[i - 1];
    
    for (i = 0; i < n; i++) w.push_back(sum[i]);
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    for (i = 0; i < n; i++) ans += v[i] * w[i];
    
    printf("%I64d\n", ans);
    
    return 0;
}