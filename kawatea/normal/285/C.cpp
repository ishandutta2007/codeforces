#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    long long ans = 0;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) ans += abs(v[i] - i - 1);
    
    printf("%I64d\n", ans);
    
    return 0;
}