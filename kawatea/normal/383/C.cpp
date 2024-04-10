#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int c;
vector <int> v[200000];
int a[200000];
int b[200000][3];
long long bit[2][400001];

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
    while (i <= 400000) {
        bit[x][i] += v;
        i += i & -i;
    }
}

void dfs(int x, int y, int z)
{
    int i;
    
    b[x][0] = z;
    b[x][1] = c++;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        dfs(v[x][i], x, 1 - z);
    }
    
    b[x][2] = c++;
}

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    
    dfs(0, -1, 0);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 1) {
            int y, z;
            
            scanf("%d %d", &y, &z);
            
            y--;
            
            if (b[y][0] == 1) z = -z;
            
            add(0, b[y][1] + 1, z);
            add(0, b[y][2] + 1, -z);
            add(1, b[y][1] + 1, -z);
            add(1, b[y][2] + 1, z);
        } else {
            int y;
            
            scanf("%d", &y);
            
            y--;
            
            printf("%I64d\n", a[y] + sum(b[y][0], b[y][1] + 1));
        }
    }
    
    return 0;
}