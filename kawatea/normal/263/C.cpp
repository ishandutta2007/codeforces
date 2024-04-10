#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map <int, int> mp[100001];

int main()
{
    int n, p = 0, q = 0, i, j, k;
    int a[100000];
    vector <int> v, w;
    map <int, int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < 2 * n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        mp[x][y]++;
        mp[y][x]++;
    }
    
    for (i = 1; i <= n; i++) {
        if (mp[i].size() != 4) {
            puts("-1");
            
            return 0;
        }
    }
    
    if (n == 5) {
        puts("1 2 3 4 5");
        
        return 0;
    } else if (n == 6) {
        int c[6] = {0};
        
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 6; j++) {
                if (c[j] == 0) {
                    a[i] = j + 1;
                    c[j] = 1;
                    
                    for (k = 0; k < 6; k++) {
                        if (k == j) continue;
                        
                        if (mp[j + 1].count(k + 1)) continue;
                        
                        a[i + 3] = k + 1;
                        c[k] = 1;
                        
                        break;
                    }
                    
                    break;
                }
            }
        }
        
        for (i = 0; i < 6; i++) {
            if (i > 0) putchar(' ');
            
            printf("%d", a[i]);
        }
        
        puts("");
        
        return 0;
    }
    
    a[0] = 1;
    a[1] = a[2] = -1;
    
    for (it = mp[1].begin(); it != mp[1].end(); it++) v.push_back(it->first);
    
    for (i = 0; i < v.size(); i++) {
        int c = 0;
        
        for (j = 0; j < v.size(); j++) {
            if (i == j) continue;
            
            if (mp[v[i]].count(v[j])) c++;
        }
        
        if (c == 2) {
            a[1] = v[i];
            p++;
        } else if (c == 1) {
            w.push_back(v[i]);
            q++;
        } else {
            puts("-1");
            
            return 0;
        }
    }
    
    if (p != 2 || q != 2) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < w.size(); i++) {
        if (mp[a[1]].count(w[i])) {
            a[2] = w[i];
            
            break;
        }
    }
    
    if (a[1] == -1 || a[2] == -1) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 3; i < n; i++) {
        for (it = mp[a[i - 1]].begin(); it != mp[a[i - 1]].end(); it++) {
            if (it->first == a[i - 2] || it->first == a[i - 3]) continue;
            
            if (mp[a[i - 2]].count(it->first)) {
                a[i] = it->first;
                
                break;
            }
        }
        
        if (it == mp[a[i - 1]].end()) {
            puts("-1");
            
            return 0;
        }
    }
    
    if (!mp[a[n - 1]].count(1) || !mp[a[n - 2]].count(1)) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}