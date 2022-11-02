#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int par[1000];
int a[1000];
int c[1000];

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
    int n, k, ans, num, i, j;
    vector <pair<int, int> > v;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] - a[i] == (j - i) * k) {
                unite(i, j);
            }
        }
    }
    
    for (i = 0; i < n; i++) c[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (c[i] > 0) v.push_back(make_pair(c[i], i));
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < n; j++) {
            if (find(j) == v[i].second) {
                ans = n - v[i].first;
                num = a[j] - j * k;
                
                break;
            }
        }
        
        if (num > 0) break;
    }
    
    printf("%d\n", ans);
    
    for (i = 0; i < n; i++) {
        if (a[i] == num + i * k) continue;
        
        if (a[i] < num + i * k) {
            printf("+ %d %d\n", i + 1, num + i * k - a[i]);
        } else {
            printf("- %d %d\n", i + 1, a[i] - num - i * k);
        }
    }
    
    return 0;
}