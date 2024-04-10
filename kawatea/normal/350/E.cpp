#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, i, j;
    int a[300] = {0};
    int b[300][300] = {0};
    vector <int> v, w;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < k; i++) {
        int x;
        
        scanf("%d", &x);
        
        x--;
        
        a[x] = 1;
        v.push_back(x);
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) w.push_back(i);
    }
    
    while (v.size() < 2) {
        v.push_back(w.back());
        
        w.pop_back();
    }
    
    if (w.size() == 0) {
        puts("-1");
        
        return 0;
    }
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    if ((v.size() - 1) * (v.size() - 2) / 2 + w.size() * (w.size() - 1) / 2 + v.size() * w.size() < m) {
        puts("-1");
        
        return 0;
    }
    
    a[v[0]] = 2;
    
    for (i = 1; i < v.size(); i++) a[v[i]] = 1;
    for (i = 0; i < w.size(); i++) a[w[i]] = 0;
    
    for (i = 1; i < v.size() - 1; i++) b[v[i]][v[i + 1]] = b[v[i + 1]][v[i]] = 1;
    for (i = 0; i < w.size() - 1; i++) b[w[i]][w[i + 1]] = b[w[i + 1]][w[i]] = 1;
    
    b[v[0]][w[0]] = b[w[0]][v[0]] = 1;
    b[v[1]][w[0]] = b[w[0]][v[1]] = 1;
    
    m -= n - 1;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] + a[j] == 3) continue;
            if (b[i][j] == 1) continue;
            if (m == 0) break;
            
            b[i][j] = 1;
            m--;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i][j] == 1) printf("%d %d\n", i + 1, j + 1);
        }
    }
    
    return 0;
}