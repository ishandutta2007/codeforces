#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    long long ans = 0;
    int a[100];
    int b[100] = {0};
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        b[x - 1]++;
    }
    
    for (i = 0; i < n; i++) {
        if (b[i] == 0) {
            ans += a[i];
        } else {
            v.push_back(a[i]);
        }
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (v[i] > ans) {
            ans += v[i];
        } else {
            ans *= 2;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}