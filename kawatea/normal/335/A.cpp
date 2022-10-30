#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i, j;
    int a[26] = {0};
    char s[1001];
    vector <pair<int, int> > v;
    
    scanf("%s", s);
    scanf("%d", &n);
    
    m = strlen(s);
    
    for (i = 0; i < m; i++) a[s[i] - 'a']++;
    
    for (i = 0; i < 26; i++) {
        if (a[i] > 0) v.push_back(make_pair(a[i], i));
    }
    
    if (v.size() > n) {
        puts("-1");
        
        return 0;
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 1; ; i++) {
        int c = 0;
        
        for (j = 0; j < v.size(); j++) {
            c += (v[j].first + i - 1) / i;
        }
        
        if (c <= n) {
            int p = 0;
            char ans[1001];
            
            for (j = 0; j < v.size(); j++) {
                c = (v[j].first + i - 1) / i;
                
                while (c--) ans[p++] = 'a' + v[j].second;
            }
            
            while (p < n) ans[p++] = 'a';
            
            ans[n] = '\0';
            
            printf("%d\n", i);
            printf("%s\n", ans);
            
            return 0;
        }
    }
    
    return 0;
}