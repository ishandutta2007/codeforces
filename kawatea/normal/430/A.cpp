#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100];

int main()
{
    int n, m, i;
    vector <pair<int, int> > v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i += 2) a[v[i].second] = 1;
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}