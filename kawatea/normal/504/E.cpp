#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long base = 1009;
long long mod = 1000000007;
char s[300001];
vector <int> v[300000];
int parent[19][300000];
int parent2[300000][4][64];
int depth[300000];
long long pow[300001];
long long rpow[300001];
long long hash[300001];
long long rhash[300001];

void dfs(int x, int y, int z)
{
    parent[0][x] = y;
    depth[x] = z;
    
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] != y) dfs(v[x][i], x, z + 1);
    }
}

void init(int n)
{
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < n; j++) {
            parent[i][j] = -1;
        }
    }
    
    dfs(0, -1, 0);
    
    for (int i = 0; i + 1 < 19; i++) {
        for (int j = 0; j < n; j++) {
            if (parent[i][j] == -1) {
                parent[i + 1][j] = -1;
            } else {
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            parent2[i][j][0] = i;
            
            for (int k = 1; k < 64; k++) {
                parent2[i][j][k] = parent[j * 6][parent2[i][j][k - 1]];
            }
        }
    }
}

int lca(int x, int y)
{
    if (depth[x] > depth[y]) swap(x, y);
    
    for (int i = 0; i < 19; i++) {
        if (((depth[y] - depth[x]) >> i) & 1) y = parent[i][y];
    }
    
    if (x == y) return x;
    
    for (int i = 18; i >= 0; i--) {
        if (parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    
    return parent[0][x];
}

long long mod_inverse(long long a, long long m)
{
    long long ans = 1;
    
    while (a > 1) {
        long long b = m % a;
        
        if (b < (a >> 1)) {
            ans = ans * (m - m / a) % m;
            a = b;
        } else {
            ans = ans * (m / a + 1) % m;
            a = a - b;
        }
    }
    
    return ans;
}

void dfs2(int x, int y)
{
    int i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        hash[v[x][i]] = (hash[x] * base + s[v[x][i]]) % mod;
        rhash[v[x][i]] = (s[v[x][i]] * pow[depth[v[x][i]]] + rhash[x]) % mod;
        
        dfs2(v[x][i], x);
    }
}

int up(int x, int y)
{
    int i;
    
    for (i = 0; i < 4 && y > 0; i++) {
        x = parent2[x][i][y & 63];
        y >>= 6;
    }
    
    return x;
}

long long get(int x, int y, int z)
{
    long long h1 = 0, h2 = 0, h;
    
    if (x != -1) h1 = hash[x];
    if (y != -1) h2 = hash[y];
    
    h = h2 - h1 * pow[z] % mod;
    
    if (h < 0) h += mod;
    
    return h;
}

long long rget(int x, int y, int z)
{
    long long h1 = 0, h2 = 0, h;
    
    if (x != -1) h1 = rhash[x];
    if (y != -1) h2 = rhash[y];
    
    h = h2 - h1;
    
    if (h < 0) h += mod;
    
    return h * rpow[depth[y] - z + 1] % mod;
}

int calc(int x1, int x2, int m)
{
    int l = 0, r = m, mid = (l + r) / 2;
    
    while (r - l > 1) {
        if (get(up(x1, mid), x1, mid) == get(up(x2, mid), x2, mid)) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    return l;
}

int calc2(int x1, int y1, int x2, int m)
{
    int l = 0, r = m, mid = (l + r) / 2, z1 = up(x1, y1);
    
    while (r - l > 1) {
        if (rget(z1, up(x1, y1 - mid), mid) == get(up(x2, mid), x2, mid)) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    return l;
}

int calc3(int x1, int y1, int x2, int y2, int m)
{
    int l = 0, r = m, mid = (l + r) / 2, z1 = up(x1, y1), z2 = up(x2, y2);
    
    while (r - l > 1) {
        if (get(z1, up(x1, y1 - mid), mid) == get(z2, up(x2, y2 - mid), mid)) {
            l = mid;
            mid = (l + r) / 2;
        } else {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    
    return l;
}

int main()
{
    int n, m, i;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    init(n);
    
    pow[0] = 1;
    
    for (i = 0; i < n; i++) pow[i + 1] = pow[i] * base % mod;
    
    for (i = 0; i <= n; i++) rpow[i] = mod_inverse(pow[i], mod);
    
    hash[0] = rhash[0] = s[0];
    
    dfs2(0, -1);
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int a, b, c, d, x, y, z1, z2, w1, w2, ans = 0, r = 0;
        
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        a--;
        b--;
        c--;
        d--;
        
        x = lca(a, b);
        y = lca(c, d);
        
        z1 = depth[a] - depth[x];
        z2 = depth[c] - depth[y];
        w1 = depth[b] - depth[x];
        w2 = depth[d] - depth[y];
        
        if (z1 + w1 < z2 + w2) {
            if (z2 >= z1 + w1) {
                if (s[b] == s[up(c, z1 + w1)]) r = 1;
            } else {
                if (s[b] == s[up(d, z2 + w2 - z1 - w1)]) r = 1;
            }
        } else {
            if (z1 >= z2 + w2) {
                if (s[d] == s[up(a, z2 + w2)]) r = 1;
            } else {
                if (s[d] == s[up(b, z1 + w1 - z2 - w2)]) r = 1;
            }
        }
        
        if (z1 > z2) {
            swap(a, c);
            swap(b, d);
            swap(x, y);
            swap(z1, z2);
            swap(w1, w2);
        }
        
        if (z1 > 0) {
            if (get(x, a, z1) == get(up(c, z1), c, z1)) {
                ans += z1;
                
                a = x;
                c = up(c, z1);
                z2 -= z1;
            } else {
                printf("%d\n", calc(a, c, z1));
                
                continue;
            }
        }
        
        if (min(z2, w1) > 0) {
            int p = min(z2, w1);
            
            if (rget(up(b, w1 + 1), up(b, w1 + 1 - p), p) == get(up(c, p), c, p)) {
                ans += p;
                
                c = up(c, p);
                w1 -= p;
            } else {
                printf("%d\n", ans + calc2(b, w1 + 1, c, p));
                
                continue;
            }
        }
        
        if (w1 > w2) {
            swap(a, c);
            swap(b, d);
            swap(x, y);
            swap(w1, w2);
        }
        
        if (w1 > 0) {
            if (get(up(b, w1 + 1), up(b, 1), w1) == get(up(d, w2 + 1), up(d, w2 + 1 - w1), w1)) {
                ans += w1;
                
                w2 -= w1;
            } else {
                printf("%d\n", ans + calc3(b, w1 + 1, d, w2 + 1, w1));
                
                continue;
            }
        }
        
        printf("%d\n", ans + r);
    }
    
    return 0;
}