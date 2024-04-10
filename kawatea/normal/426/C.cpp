#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, ans = -1e9, i, j, l;
    int a[200];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int sum = 0;
            vector <int> v, w;
            
            for (l = 0; l < n; l++) {
                if (l >= i && l <= j) {
                    v.push_back(a[l]);
                } else {
                    w.push_back(a[l]);
                }
            }
            
            sort(v.begin(), v.end());
            sort(w.begin(), w.end());
            reverse(w.begin(), w.end());
            
            for (l = 0; l < v.size() && l < w.size() && l < k; l++) {
                if (v[l] < w[l]) swap(v[l], w[l]);
            }
            
            for (l = 0; l < v.size(); l++) sum += v[l];
            
            ans = max(ans, sum);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}