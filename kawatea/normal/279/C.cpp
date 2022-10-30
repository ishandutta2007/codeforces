#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    int a[100000];
    vector <int> v, w;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    v.push_back(0);
    w.push_back(0);
    
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            v.push_back(v.back() + 1);
        } else {
            v.push_back(v.back());
        }
        
        if (a[i] > a[i - 1]) {
            w.push_back(w.back() + 1);
        } else {
            w.push_back(w.back());
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (v[x] == v[y] || w[x] == w[y]) {
            puts("Yes");
        } else {
            int p = lower_bound(v.begin(), v.end(), v[x] + 1) - v.begin();
            
            if (w[p] == w[y]) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    
    return 0;
}