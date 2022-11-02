#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    double ans = 0, sum = 0, p = 1;
    vector <double> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        double x;
        
        scanf("%lf", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        sum += (p - sum) * v[i];
        p *= (1 - v[i]);
        
        ans = max(ans, sum);
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}