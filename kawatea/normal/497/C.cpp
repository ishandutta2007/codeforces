#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int ans[100000];

int main()
{
    int n, m, i, j;
    vector <pair<int, pair<int, int> > > v;
    vector <pair<int, pair<int, pair<int, int> > > > w;
    set <pair<int, pair<int, int> > > s;
    set <pair<int, pair<int, int> > >::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(make_pair(x, make_pair(y, i)));
    }
    
    sort(v.begin(), v.end());
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        w.push_back(make_pair(x, make_pair(y, make_pair(z, i + 1))));
    }
    
    sort(w.begin(), w.end());
    
    for (i = 0, j = 0; i < n; i++) {
        while (j < m) {
            if (w[j].first > v[i].first) break;
            
            s.insert(make_pair(w[j].second.first, make_pair(w[j].second.second.first, w[j].second.second.second)));
            
            j++;
        }
        
        it = s.lower_bound(make_pair(v[i].second.first, make_pair(-1, -1)));
        
        if (it == s.end()) {
            puts("NO");
            
            return 0;
        } else {
            ans[v[i].second.second] = it->second.second;
            
            if (it->second.first > 1) s.insert(make_pair(it->first, make_pair(it->second.first - 1, it->second.second)));
            
            s.erase(it);
        }
    }
    
    puts("YES");
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}