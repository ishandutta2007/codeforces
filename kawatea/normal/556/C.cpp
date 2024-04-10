#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector <int> v[100000];

int main()
{
    int n, k, ans = 0, i, j;
    map <int, int> mp;
    map <int, int>::iterator it;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < k; i++) {
        int m;
        
        scanf("%d", &m);
        
        for (j = 0; j < m; j++) {
            int x;
            
            scanf("%d", &x);
            
            v[i].push_back(x);
            
            mp[x]++;
        }
    }
    
    for (it = mp.begin(), i = 0; it != mp.end(); it++, i++) it->second = i;
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < v[i].size(); j++) {
            v[i][j] = mp[v[i][j]];
        }
    }
    
    for (i = 0; i < k; i++) {
        if (v[i][0] != 0) {
            ans += (v[i].size() - 1) * 2;
        } else {
            for (j = 0; j + 1 < v[i].size(); j++) {
                if (v[i][j] + 1 != v[i][j + 1]) {
                    ans += (v[i].size() - j - 1) * 2;
                    
                    break;
                }
            }
        }
    }
    
    ans += k - 1;
    
    printf("%d\n", ans);
    
    return 0;
}