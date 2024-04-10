#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, x = 0, i, j;
    vector <pair<int, int> > v;
    map <int, vector <int> > mp;
    map <int, vector <int> >::iterator it;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        mp[x].push_back(y);
    }
    
    for (it = mp.begin(); it != mp.end(); it++) sort(it->second.begin(), it->second.end());
    
    v.push_back(make_pair(0, 0));
    
    for (it = mp.begin(); it != mp.end(); it++) {
        vector <pair<int, int> > w;
        
        if (x < it->first) {
            int y = v[0].first;
            
            v.clear();
            
            v.push_back(make_pair(y, n - 1));
        }
        
        for (i = 0, j = 0; i < v.size() && j < it->second.size();) {
            if (v[i].second < it->second[j]) {
                w.push_back(make_pair(v[i].first, it->second[j] - 1));
                
                while (i < v.size() && v[i].second < it->second[j]) i++;
                
                if (i < v.size()) {
                    v[i].first = max(v[i].first, it->second[j] + 1);
                    if (v[i].first > v[i].second) i++;
                }
            } else if (v[i].first > it->second[j]) {
                j++;
            } else {
                if (v[i].first != it->second[j]) w.push_back(make_pair(v[i].first, it->second[j] - 1));
                
                if (v[i].second != it->second[j]) {
                    v[i].first = it->second[j] + 1;
                } else {
                    i++;
                }
                
                j++;
            }
        }
        
        if (i < v.size()) w.push_back(make_pair(v[i].first, n - 1));
        
        if (w.size() == 0) {
            puts("-1");
            
            return 0;
        }
        
        v.swap(w);
        
        x = it->first + 1;
    }
    
    if (x == n && v.back().second != n - 1) {
        puts("-1");
    } else {
        printf("%d\n", (n - 1) * 2);
    }
    
    return 0;
}