#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector <int> v[4000];

int main()
{
    int n, ans = 1, i, j;
    int a[4000];
    map <int, int> mp;
    map <int, int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        mp[a[i]]++;
        
        ans = max(ans, mp[a[i]]);
    }
    
    for (it = mp.begin(), i = 0; it != mp.end(); it++, i++) it->second = i;
    
    for (i = 0; i < n; i++) v[mp[a[i]]].push_back(i);
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int p = 0, q = 0, r = -1, c = 0;
            
            if (min(v[i].size(), v[j].size()) * 2 + 1 <= ans) continue;
            
            while (p < v[i].size() && q < v[j].size()) {
                if (v[i][p] < v[j][q]) {
                    if (r != 0) c++;
                    
                    r = 0;
                    
                    p++;
                } else {
                    if (r != 1) c++;
                    
                    r = 1;
                    
                    q++;
                }
            }
            
            if (p < v[i].size() && r != 0) c++;
            if (q < v[j].size() && r != 1) c++;
            
            ans = max(ans, c);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}