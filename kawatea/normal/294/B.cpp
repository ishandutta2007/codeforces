#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 1e9, i, j, k;
    vector <int> v, w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        if (x == 1) {
            v.push_back(y);
        } else {
            w.push_back(y);
        }
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    for (i = 0; i <= v.size(); i++) {
        for (j = 0; j <= w.size(); j++) {
            int sum = 0;
            
            for (k = i; k < v.size(); k++) sum += v[k];
            for (k = j; k < w.size(); k++) sum += w[k];
            
            if (i + j * 2 < sum) continue;
            
            ans = min(ans, i + j * 2);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}