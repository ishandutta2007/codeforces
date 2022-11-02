#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, sum = 0, ans = 0, i, j;
    vector <int> v[100];
    vector <int> w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        for (j = 0; j < x; j++) {
            int y;
            
            scanf("%d", &y);
            
            sum += y;
            
            v[i].push_back(y);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i].size() / 2; j++) ans += v[i][j];
        
        if (v[i].size() % 2 == 1) w.push_back(v[i][j]);
    }
    
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    for (i = 0; i < w.size(); i++) {
        if (i % 2 == 0) ans += w[i];
    }
    
    printf("%d %d\n", ans, sum - ans);
    
    return 0;
}