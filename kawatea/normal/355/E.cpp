#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int sum[1000001];

int main()
{
    int n, k, i, j;
    vector <int> v;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) sum[v[i]]++;
    
    for (i = 1; i <= 1000000; i++) sum[i] += sum[i - 1];
    
    for (i = v[0]; i >= 0; i--) {
        if (i <= k + 1) break;
        
        for (j = 0; j <= 1000000; j += i) {
            if (sum[min(1000000, j + i - 1)] - sum[min(1000000, j + k)] != 0) {
                break;
            }
        }
        
        if (j > 1000000) break;
    }
    
    printf("%d\n", i);
    
    return 0;
}