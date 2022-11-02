#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long bit[2][100001];
vector <int> v[100000];
pair <int, int> p[100000];
vector <vector <long long> > bit2[2];

long long sum(int x, int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[x][i];
        i -= i & -i;
    }
    
    return s;
}

void add(int x, int i, long long v)
{
    while (i <= 100000) {
        bit[x][i] += v;
        i += i & -i;
    }
}

long long get(int x, int y)
{
    long long s = 0;
    
    s += sum(0, y + 1) + sum(1, y + 1) * (y + 1);
    s -= sum(0, x) + sum(1, x) * x;
    
    return s;
}

void set(int x, int y, long long z)
{
    add(0, x + 1, -z * x);
    add(1, x + 1, z);
    add(0, y + 2, z * (y + 1));
    add(1, y + 2, -z);
}

long long sum2(int x, int y, int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit2[x][y][i];
        i -= i & -i;
    }
    
    return s;
}

void add2(int x, int y, int i, long long v)
{
    while (i < bit2[x][y].size()) {
        bit2[x][y][i] += v;
        i += i & -i;
    }
}

long long get2(int x, int y, int z)
{
    long long s = 0;
    
    s += sum2(0, x, z + 1) + sum2(1, x, z + 1) * (z + 1);
    s -= sum2(0, x, y) + sum2(1, x, y) * y;
    
    return s;
}

void set2(int x, int y, int z, long long w)
{
    add2(0, x, y + 1, -w * y);
    add2(1, x, y + 1, w);
    add2(0, x, z + 2, w * (z + 1));
    add2(1, x, z + 2, -w);
}

void dfs(int x, int y, int z, int w)
{
    int i;
    
    if (x == 0) {
        for (i = 0; i < v[x].size(); i++) {
            dfs(v[x][i], x, i, 0);
        }
    } else {
        p[x] = make_pair(z, w);
        
        if (v[x].size() == 1) {
            bit2[0].push_back(vector <long long>());
            bit2[0].back().resize(w + 2, 0);
            bit2[1].push_back(vector <long long>());
            bit2[1].back().resize(w + 2, 0);
        }
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            dfs(v[x][i], x, z, w + 1);
        }
    }
}

int main()
{
    int n, q, i;
    long long s = 0;
    
    scanf("%d %d", &n, &q);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(0, -1, 0, 0);
    
    for (i = 0; i < q; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 0) {
            int y, z, w;
            
            scanf("%d %d %d", &y, &z, &w);
            
            y--;
            
            if (y == 0) {
                set(0, w - 1, z);
                
                s += z;
            } else {
                set2(p[y].first, max(0, p[y].second - w), min((int)bit2[0][p[y].first].size() - 1, p[y].second + w), z);
                
                if (p[y].second < w) {
                    s += z;
                    
                    if (w - p[y].second - 2 >= 0) {
                        set(0, w - p[y].second - 2, z);
                        
                        set2(p[y].first, 0, min((int)bit2[0][p[y].first].size() - 1, w - p[y].second - 2), -z);
                    }
                }
            }
        } else {
            int y;
            
            scanf("%d", &y);
            
            y--;
            
            if (y == 0) {
                printf("%d\n", (int)s);
            } else {
                long long ans;
                
                ans = get(p[y].second, p[y].second);
                ans += get2(p[y].first, p[y].second, p[y].second);
                
                printf("%d\n", (int)ans);
            }
        }
    }
    
    return 0;
}