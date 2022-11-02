#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[3000];
int par[3000];
int cnt[3000];

void init(int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        par[i] = i;
        cnt[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) return x;
    
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main()
{
    int n, l, r, m, i;
    vector <pair<int, pair<int, int> > > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        v.push_back(make_pair(z, make_pair(x - 1, y - 1)));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    if (n == 1) {
        puts("0");
        
        return 0;
    }
    
    l = 0, r = n - 1, m = (l + r) / 2;
    
    while (r - l > 1) {
        int c = 0, sum = 0;
        
        init(n);
        
        for (i = 0; i < m; i++) unite(v[i].second.first, v[i].second.second);
        
        for (i = 0; i < n; i++) cnt[find(i)]++;
        
        for (i = 0; i < n; i++) {
            if (cnt[i] > cnt[c]) c = i;
        }
        
        for (i = 0; i < n; i++) {
            if (find(i) != c) sum += a[i];
        }
        
        if (sum >= cnt[c]) {
            l = m;
            m = (l + r) / 2;
        } else {
            r = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%d\n", v[l].first);
    
    return 0;
}