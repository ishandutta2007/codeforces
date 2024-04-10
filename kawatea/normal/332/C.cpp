#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, p, k, i, j, l;
    vector <pair<int, pair<int, int> > > v, w, z, x;
    vector <int> ans;
    
    scanf("%d %d %d", &n, &p, &k);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(make_pair(y, make_pair(-x, i + 1)));
    }
    
    sort(v.begin(), v.end());
    
    for (i = p - k; i < v.size(); i++) {
        w.push_back(make_pair(-v[i].second.first, make_pair(v[i].first, v[i].second.second)));
    }
    
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    for (i = 0; i < k; i++) {
        z.push_back(make_pair(w[i].second.first, make_pair(w[i].first, w[i].second.second)));
    }
    
    sort(z.begin(), z.end());
    
    for (i = k; i < w.size(); i++) {
        x.push_back(make_pair(w[i].second.first, make_pair(w[i].first, w[i].second.second)));
    }
    
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    
    for (i = 0; i < x.size(); i++) {
        if (ans.size() >= p - k) break;
        
        if (x[i].first < z[0].first || (x[i].first == z[0].first && x[i].second.first > z[0].second.first)) ans.push_back(x[i].second.second);
    }
    
    for (i = p - k - 1; i >= 0; i--) {
        if (ans.size() >= p - k) break;
        
        ans.push_back(v[i].second.second);
    }
    
    for (i = 0; i < z.size(); i++) ans.push_back(z[i].second.second);
    
    for (i = 0; i < ans.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}