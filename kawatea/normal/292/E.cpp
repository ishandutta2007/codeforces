#include <cstdio>
#include <vector>

using namespace std;

int n;
int bit[501][100001];

int sum(int x, int i)
{
    int s = 0;
    
    while (i > 0) {
        s += bit[x][i];
        i -= i & -i;
    }
    
    return s;
}

void add(int x, int i, int v)
{
    while (i <= n) {
        bit[x][i] += v;
        i += i & -i;
    }
}

int main()
{
    int m, c = 0, i, j;
    int a[100000];
    int b[100000];
    vector <pair<int, pair<int, int> > > v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < m; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int x, y, z;
            
            scanf("%d %d %d", &x, &y, &z);
            
            if (v.size() > 0 && v.size() % 200 == 0) {
                c++;
                
                for (j = 0; j <= n; j++) bit[c][j] = bit[c - 1][j];
            }
            
            v.push_back(make_pair(x - 1, make_pair(y - 1, z)));
            
            add(c, y, 1);
            add(c, y + z, -1);
        } else {
            int x, y, l, r, mid;
            
            scanf("%d", &x);
            
            y = sum(c, x);
            
            if (y == 0) {
                printf("%d\n", b[x - 1]);
                
                continue;
            }
            
            l = -1, r = c, mid = (l + r) / 2;
            
            while (r - l > 1) {
                int p = sum(mid, x);
                
                if (p < y) {
                    l = mid;
                    mid = (l + r) / 2;
                } else {
                    r = mid;
                    mid = (l + r) / 2;
                }
            }
            
            if (l >= 0) y -= sum(l, x);
            
            x--;
            
            for (j = (l + 1) * 200; j < v.size(); j++) {
                int p = v[j].second.first;
                int q = v[j].second.second;
                
                if (x >= p && x < p + q) y--;
                
                if (y == 0) {
                    printf("%d\n", a[x - p + v[j].first]);
                    
                    break;
                }
            }
        }
    }
    
    return 0;
}