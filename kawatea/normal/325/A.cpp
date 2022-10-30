#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x1 = 1e9, y1 = 1e9, x2 = 0, y2 = 0, i, j;
    int a[5][4];
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        x1 = min(x1, a[i][0]);
        y1 = min(y1, a[i][1]);
        x2 = max(x2, a[i][2]);
        y2 = max(y2, a[i][3]);
        
        v.push_back(a[i][0]);
        v.push_back(a[i][2]);
    }
    
    if (x2 - x1 != y2 - y1) {
        puts("NO");
        
        return 0;
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        int p = y1;
        vector <pair<int, int> > w;
        
        if (v[i] >= x2) break;
        
        for (j = 0; j < n; j++) {
            if (a[j][0] <= v[i] && a[j][2] > v[i]) w.push_back(make_pair(a[j][1], a[j][3]));
        }
        
        sort(w.begin(), w.end());
        
        for (j = 0; j < w.size(); j++) {
            if (w[j].first > p) {
                puts("NO");
                
                return 0;
            }
            
            p = w[j].second;
        }
        
        if (p != y2) {
            puts("NO");
            
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}