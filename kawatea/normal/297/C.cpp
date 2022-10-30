#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c = 0, i;
    int a[100000];
    int b[100000];
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < (n + 2) / 3; i++) {
        a[v[i].second] = 0;
        b[v[i].second] = v[i].first;
    }
    
    for (; i < n; i++) {
        if (c % 2 == 0) {
            a[v[i].second] = c / 2;
            b[v[i].second] = v[i].first - c / 2;
        } else {
            a[v[i].second] = v[i].first - c / 2;
            b[v[i].second] = c / 2;
        }
        
        c++;
    }
    
    puts("YES");
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");

    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", b[i]);
    }
    
    puts("");

    return 0;
}