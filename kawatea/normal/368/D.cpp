#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[200000];
int b[200000];

int main()
{
    int n, m, p, i, j, k;
    vector <int> v;
    
    scanf("%d %d %d", &n, &m, &p);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < p && i + (long long)(m - 1) * p < n; i++) {
        map <int, int> mp;
        
        for (j = 0; j < m; j++) mp[b[j]]++;
        
        for (j = 0, k = i; j < m; j++, k += p) {
            mp[a[k]]--;
            
            if (mp[a[k]] == 0) mp.erase(a[k]);
        }
        
        for (j = i; ; j += p, k += p) {
            if (mp.size() == 0) v.push_back(j + 1);
            
            if (k >= n) break;
            
            mp[a[k]]--;
            
            if (mp[a[k]] == 0) mp.erase(a[k]);
            
            mp[a[j]]++;
            
            if (mp[a[j]] == 0) mp.erase(a[j]);
        }
    }
    
    sort(v.begin(), v.end());
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", v[i]);
    }
    
    puts("");
    
    return 0;
}