#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    vector <pair<int, int> > v;
    vector <int> w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i + 1));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i + 1 < n; i++) {
        if (v[i].first == v[i + 1].first) w.push_back(i);
    }
    
    if (w.size() <= 1) {
        puts("NO");
    } else {
        puts("YES");
        
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            printf("%d", v[i].second);
        }
        
        puts("");
        
        swap(v[w[0]], v[w[0] + 1]);
        
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            printf("%d", v[i].second);
        }
        
        puts("");
        
        swap(v[w[1]], v[w[1] + 1]);
        
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            printf("%d", v[i].second);
        }
        
        puts("");
    }
    
    return 0;
}