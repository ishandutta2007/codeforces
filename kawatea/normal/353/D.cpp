#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char s[1000001];

int main()
{
    int n, c = 0, ans = 0, i, j;
    vector <int> v;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (s[i] != s[j]) break;
        }
        
        if (i > 0 || s[i] == 'M') v.push_back(j - i);
        
        i = j - 1;
    }
    
    if (s[n - 1] == 'M') v.pop_back();
    
    if (v.size() <= 1) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < v.size(); i += 2) {
        c += v[i];
        
        if (c - 1 <= ans) {
            ans += v[i + 1];
        } else {
            ans += c - 1 - ans;
            ans += v[i + 1];
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}