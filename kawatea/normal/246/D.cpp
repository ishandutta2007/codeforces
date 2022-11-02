#include <cstdio>
#include <set>

using namespace std;

set <int> s[100001];

int main()
{
    int n, m, p = 0, q = -1, i;
    int a[100000];
    set <int> t;
    set <int>::iterator it;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        t.insert(a[i]);
    }
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (a[x] == a[y]) continue;
        
        s[a[x]].insert(a[y]);
        s[a[y]].insert(a[x]);
    }
    
    for (it = t.begin(); it != t.end(); it++) {
        if ((int)s[*it].size() > q) {
            p = *it;
            q = s[*it].size();
        }
    }
    
    printf("%d\n", p);
    
    return 0;
}