#include <cstdio>

using namespace std;

int n, p;
char s[1001];
char ans[1001];

int dfs(int x, int y)
{
    int i;
    
    if (x == n) return y;
    
    if (y == 0) {
        ans[x] = s[x];
        
        if (dfs(x + 1, 0)) return 1;
        
        for (i = s[x] - 'a' + 1; i < p; i++) {
            ans[x] = i + 'a';
            
            if (x > 0 && ans[x] == ans[x - 1]) continue;
            if (x > 1 && ans[x] == ans[x - 2]) continue;
            
            if (dfs(x + 1, 1)) return 1;
        }
        
        return 0;
    } else {
        for (i = 0; i < p; i++) {
            ans[x] = i + 'a';
            
            if (x > 0 && ans[x] == ans[x - 1]) continue;
            if (x > 1 && ans[x] == ans[x - 2]) continue;
            
            if (dfs(x + 1, 1)) return 1;
        }
        
        return 0;
    }
}

int main()
{
    scanf("%d %d", &n, &p);
    scanf("%s", s);
    
    if (dfs(0, 0)) {
        ans[n] = '\0';
        
        printf("%s\n", ans);
    } else {
        puts("NO");
    }
    
    return 0;
}