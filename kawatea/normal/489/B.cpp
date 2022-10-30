#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, ans = 0, i, j;
    vector <int> v, w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        w.push_back(x);
    }
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    for (i = 0, j = 0; i < v.size() && j < w.size(); ) {
        if (abs(v[i] - w[j]) <= 1) {
            ans++;
            i++;
            j++;
        } else if (v[i] < w[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}