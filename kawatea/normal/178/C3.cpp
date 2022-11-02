#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int a[200000], b[200000][2], f[200000][2];
int bit[1 << 18];
vector <vector <int> > v;
map <int, int> mp;

int sum(int i)
{
    int s = 0;
    
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    
    return s;
}

void add(int i, int x)
{
    while (i < (1 << 18)) {
        bit[i] += x;
        i += i & -i;
    }
}

int insert(int x, int y)
{
    int p, q, l, r, m;
    
    p = b[f[y][0]][0] + f[y][1];
    q = b[f[y][0]][1];
    
    if (sum(q + 1) - sum(p) < q - p + 1) {
        l = p;
        r = q;
        m = (l + r) / 2;
        
        while (r - l > 1) {
            if (sum(m + 1) - sum(p) < m - p + 1) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }
        
        if (a[v[f[y][0]][l - b[f[y][0]][0]]] == 0) {
            a[v[f[y][0]][l - b[f[y][0]][0]]] = 1;
            
            mp[x] = v[f[y][0]][l - b[f[y][0]][0]];
            
            add(l + 1, 1);
            
            return l - p;
        } else {
            a[v[f[y][0]][r - b[f[y][0]][0]]] = 1;
            
            mp[x] = v[f[y][0]][r - b[f[y][0]][0]];
            
            add(r + 1, 1);
            
            return r - p;
        }
    } else {
        p = b[f[y][0]][0];
        l = p;
        r = l + f[y][1] - 1;
        m = (l + r) / 2;
        
        while (r - l > 1) {
            if (sum(m + 1) - sum(p) < m - p + 1) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }
        
        if (a[v[f[y][0]][l - p]] == 0) {
            a[v[f[y][0]][l - p]] = 1;
            
            mp[x] = v[f[y][0]][l - p];
            
            add(l + 1, 1);
            
            return q - b[f[y][0]][0] - f[y][1] + l - p + 1;
        } else {
            a[v[f[y][0]][r - p]] = 1;
            
            mp[x] = v[f[y][0]][r - p];
            
            add(r + 1, 1);
            
            return q - b[f[y][0]][0] - f[y][1] + r - p + 1;
        }
    }
}

int main()
{
    int h, m, n, p = 0, i, j;
    long long ans = 0;
    
    scanf("%d %d %d", &h, &m, &n);
    
    for (i = 0; i < h; i++) f[i][0] = -1;
    
    for (i = 0; i < h; i++) {
        if (f[i][0] == -1) {
            int c = 0;
            vector <int> w;
            
            b[v.size()][0] = p;
            
            for (j = i; ; j = (j + m) % h, c++, p++) {
                if (f[j][0] >= 0) break;
                
                f[j][0] = v.size();
                f[j][1] = c;
                
                w.push_back(j);
            }
            
            b[v.size()][1] = p - 1;
            
            v.push_back(w);
        }
    }
    
    for (i = 0; i < n; i++) {
        int x, y;
        char s[2];
        
        scanf("%s %d", s, &x);
        
        if (s[0] == '+') {
            scanf("%d", &y);
            
            ans += insert(x, y);
        } else {
            y = mp[x];
            
            a[y] = 0;
            
            mp.erase(x);
            
            add(b[f[y][0]][0] + f[y][1] + 1, -1);
        }            
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}