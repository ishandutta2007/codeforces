#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    double pi = acos(-1);
    double ans = 360;
    vector <double> v;
    vector <double>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(atan2(y, x) * 180 / pi + 180);
    }
    
    sort(v.begin(), v.end());
    
    it = unique(v.begin(), v.end());
    
    v.erase(it, v.end());
    
    for (i = 0; i < v.size(); i++) {
        double x = v[i];
        double y = v[((i - 1) + v.size()) % v.size()];
        
        if (x > y) {
            ans = min(ans, 360 - x + y);
        } else {
            ans = min(ans, y - x);
        }
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}