#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

int a[100000][2];
int b[100000];
long long f[100000];
vector <int> v[100000];
vector <int> w[100000];

int check(int x)
{
    int i, j;
    
    for (i = 0; i < w[x].size(); i++) {
        int y = w[x][i];
        
        if (b[y] == 1) continue;
        
        for (j = 0; j < v[y].size(); j++) {
            if (b[v[y][j]] == 0 && v[y][j] != x) break;
        }
        
        if (j == v[y].size()) return 0;
    }
    
    return 1;
}

int main()
{
    int m, mod = 1000000009, i, j, k;
    long long ans = 0;
    set <int> s;
    map <pair<int, int>, int> mp;
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        
        mp[make_pair(a[i][0], a[i][1])] = i;
    }
    
    for (i = 0; i < m; i++) {
        for (j = -1; j <= 1; j++) {
            int x = a[i][0] + j;
            int y = a[i][1] - 1;
            
            if (mp.count(make_pair(x, y))) {
                v[i].push_back(mp[make_pair(x, y)]);
                w[mp[make_pair(x, y)]].push_back(i);
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        if (check(i) == 1) s.insert(i);
    }
    
    f[0] = 1;
    
    for (i = 1; i < m; i++) f[i] = f[i - 1] * m % mod;
    
    for (i = 0; i < m; i++) {
        int x;
        
        if (i % 2 == 0) {
            x = *s.rbegin();
        } else {
            x = *s.begin();
        }
        
        ans = (ans + f[m - i - 1] * x % mod) % mod;
        
        b[x] = 1;
        s.erase(x);
        
        for (j = 0; j < v[x].size(); j++) {
            if (b[v[x][j]] == 0 && check(v[x][j]) == 1) s.insert(v[x][j]);
        }
        
        for (j = 0; j < w[x].size(); j++) {
            int y = w[x][j];
            
            for (k = 0; k < v[y].size(); k++) {
                if (s.count(v[y][k]) && check(v[y][k]) == 0) s.erase(v[y][k]);
            }
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}