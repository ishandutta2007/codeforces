#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, h, c = -1, ans, i;
    vector <pair<int, int> > v;
    
    scanf("%d %d", &n, &h);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    ans = (v[0].first + v[1].first) - (v[n - 1].first + v[n - 2].first);
    
    for (i = 1; i < n; i++) {
        int m1 = max(v[0].first + v[1].first, v[0].first + v[i].first + h);
        int m2 = v[n - 1].first + v[n - 2].first + h;
        
        if (i != n - 1) m2 = min(m2, v[i - 1].first + v[n - 1].first);
        if (i > 1) m2 = min(m2, v[i - 1].first + v[i - 2].first);
        if (i + 2 < n) m2 = min(m2, v[n - 2].first + v[n - 3].first);
        
        if (m1 - m2 < ans) {
            c = i;
            ans = m1 - m2;
        }
    }
    
    if (c != -1) {
        for (i = 0; i < c; i++) a[v[i].second] = 0;
        for (; i < n; i++) a[v[i].second] = 1;
        
        if (c != n - 1) a[v[n - 1].second] = 0;
    }
    
    printf("%d\n", ans);
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i] + 1);
    }
    
    puts("");
    
    return 0;
}