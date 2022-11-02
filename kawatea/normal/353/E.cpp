#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[2000001];

int dfs(int x, int y)
{
    int ans = 0, i;
    
    if (x > y) return 0;
    
    while (x <= y) {
        ans++;
        
        for (i = x; i < y; i++) {
            if (s[i] != s[x]) break;
        }
        
        x = i + 1;
    }
    
    return ans;
}

int main()
{
    int n, x, y, i, j;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) s[i + n] = s[i];
    
    for (i = 0; i < n; i++) {
        if (s[i + n] == '0' && s[i + n - 1] == '1') break;
    }
    
    for (j = i; j < n * 2; j++) {
        if (s[j] == '1') break;
    }
    
    x = j + 1;
    
    for (j = i + n - 1; j >= 0; j--) {
        if (s[j] == '0') break;
    }
    
    y = j;
    
    printf("%d\n", max(dfs(i + 1, i + n - 1), dfs(x, y) + 1));
    
    return 0;
}