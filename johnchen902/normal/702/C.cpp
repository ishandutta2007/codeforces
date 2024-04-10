#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int a[(int) 1e5], b[(int) 1e5];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < m; i++)
        scanf("%d", b + i);
    
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        while(j < m && b[j] < a[i])
            j++;
        int req = (int) 2e9;
        if(j)
            req = a[i] - b[j - 1];
        if(j < m)
            req = min(req, b[j] - a[i]);
        ans = max(ans, req);
    }
    printf("%d\n", ans);
}