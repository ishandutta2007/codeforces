#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c = 0, ans = 1e9, i, j;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n * 2; i++) {
        int x;
        
        scanf("%*d.%d", &x);
        
        if (x == 0) {
            c++;
        } else {
            v.push_back(x);
        }
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i <= n; i++) {
        int sum = 0;
        
        if (i > v.size()) break;
        
        if (i + n < v.size()) continue;
        
        for (j = 0; j < i; j++) sum += v[j];
        for (; j < v.size(); j++) sum -= 1000 - v[j];
        
        ans = min(ans, abs(sum));
    }
    
    printf("%d.%03d\n", ans / 1000, ans % 1000);
    
    return 0;
}