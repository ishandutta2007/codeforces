#include <cstdio>
#include <vector>

using namespace std;

int a[100];

int main()
{
    int n, k, x, y, i, j;
    vector <pair<int, int> > v;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < k; i++) {
        x = y = 0;
        
        for (j = 0; j < n; j++) {
            if (a[j] > a[x]) x = j;
            if (a[j] < a[y]) y = j;
        }
        
        if (x == y) break;
        
        v.push_back(make_pair(x + 1, y + 1));
        
        a[x]--;
        a[y]++;
    }
    
    x = y = 0;
    
    for (i = 0; i < n; i++) {
        if (a[i] > a[x]) x = i;
        if (a[i] < a[y]) y = i;
    }
    
    printf("%d %d\n", a[x] - a[y], v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}