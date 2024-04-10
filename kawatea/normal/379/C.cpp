#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ans[300000];

int main()
{
    int n, x = 0, i;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        ans[v[i].second] = max(x, v[i].first);
        
        x = max(x, v[i].first) + 1;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}