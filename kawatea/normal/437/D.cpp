#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int par[100000];
int cnt[100000];

void init(int n)
{
    int i;
    
    for (i = 0; i < n; i++) {
        par[i] = i;
        cnt[i] = 1;
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
    cnt[y] += cnt[x];
}

int main()
{
    int n, m, i;
    double ans = 0;
    vector <pair<int, pair<int, int> > > v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v.push_back(make_pair(min(a[x], a[y]), make_pair(x, y)));
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    init(n);
    
    for (i = 0; i < v.size(); i++) {
        int x = v[i].second.first;
        int y = v[i].second.second;
        
        if (find(x) == find(y)) continue;
        
        ans += (double)v[i].first * cnt[find(x)] * cnt[find(y)] * 2;
        
        unite(x, y);
    }
    
    printf("%lf\n", ans / n / (n - 1));
    
    return 0;
}