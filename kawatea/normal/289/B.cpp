#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, d, x, sum = 0, i, j;
    vector <int> v;
    
    scanf("%d %d %d", &n, &m, &d);
    
    for (i = 0; i < n * m; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    x = v[0] % d;
    
    for (i = 0; i < n * m; i++) {
        if (v[i] % d != x) {
            puts("-1");
            
            return 0;
        }
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n * m; i++) sum += abs(v[n * m / 2] - v[i]) / d;
    
    printf("%d\n", sum);
    
    return 0;
}