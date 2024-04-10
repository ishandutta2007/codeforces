#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, t, ans = 0, i, j;
    vector <pair<int, pair<int, int> > > v;
    map <int, pair<int, int> > mp;
    map <int, pair<int, int> >::iterator it, it2, it3, it4;
    
    scanf("%d %d", &n, &t);
    
    for (i = 0; i < n; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        v.push_back(make_pair(-x, make_pair(y, z)));
    }
    
    sort(v.begin(), v.end());
    
    mp[-1e9 - 1] = make_pair(6, 2e9);
    mp[1e9 + 1] = make_pair(1, 0);
    
    for (i = 0; i < v.size(); i++) {
        int x = v[i].second.first;
        int y = v[i].second.second;
        int z = 0;
        int w1, w2;
        vector <int> e;
        
        it = mp.lower_bound(x);
        it2 = mp.lower_bound(y);
        
        if (it->first > x) it--;
        
        for (it3 = it; it3 != it2; it3++) {
            int p, q;
            
            it4 = it3;
            it4++;
            
            p = it3->first;
            q = it4->first;
            
            e.push_back(it3->first);
            
            if ((it3->second.first & 2) && it2 != it4) continue;
            if ((it3->second.first & 4) && it != it3) continue;
            
            z = max(z, min(it3->second.second, min(y, q) - max(x, p)));
        }
        
        if (it2->first == y) {
            w1 = -1;
        } else {
            it4 = it2;
            it4--;
            
            w1 = it4->second.second;
            w2 = it4->second.first | 4;
        }
        
        it->second.first |= 2;
        
        for (j = 1; j < e.size(); j++) mp.erase(e[j]);
        
        mp[x] = make_pair(0, z);
        
        if (w1 >= 0) mp[y] = make_pair(w2, w1);
    }
    
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second.first > 0) continue;
        
        ans = max(ans, it->second.second);
    }
    
    printf("%d\n", ans);
    
    return 0;
}