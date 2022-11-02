#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int a[25][3];
int b[26];
map <pair<int, int>, pair<int, int> > mp;

int main()
{
    int n, ans = -1e9, c1, c2, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    
    if (n == 1) {
        if (a[0][0] == 0 && a[0][1] == 0) {
            puts("LM");
        } else if (a[0][0] == 0 && a[0][2] == 0) {
            puts("LW");
        } else if (a[0][1] == 0 && a[0][2] == 0) {
            puts("MW");
        } else {
            puts("Impossible");
        }
        
        return 0;
    }
    
    b[0] = 1;
    
    for (i = 1; i <= n; i++) b[i] = b[i - 1] * 3;
    
    for (i = 0; i < b[(n + 1) / 2]; i++) {
        int x = 0, y = 0, z = 0, p = i;
        
        for (j = 0; j < (n + 1) / 2; j++) {
            if (p % 3 == 0) {
                y += a[j][1];
                z += a[j][2];
            } else if (p % 3 == 1) {
                x += a[j][0];
                z += a[j][2];
            } else {
                x += a[j][0];
                y += a[j][1];
            }
            
            p /= 3;
        }
        
        if (!mp.count(make_pair(y - x, z - x)) || mp[make_pair(y - x, z - x)].first < x) {
            mp[make_pair(y - x, z - x)] = make_pair(x, i);
        }
    }
    
    for (i = 0; i < b[n / 2]; i++) {
        int x = 0, y = 0, z = 0, p = i;
        
        for (j = 0; j < n / 2; j++) {
            if (p % 3 == 0) {
                y += a[j + (n + 1) / 2][1];
                z += a[j + (n + 1) / 2][2];
            } else if (p % 3 == 1) {
                x += a[j + (n + 1) / 2][0];
                z += a[j + (n + 1) / 2][2];
            } else {
                x += a[j + (n + 1) / 2][0];
                y += a[j + (n + 1) / 2][1];
            }
            
            p /= 3;
        }
        
        if (mp.count(make_pair(x - y, x - z)) && mp[make_pair(x - y, x - z)].first + x > ans) {
            ans = mp[make_pair(x - y, x - z)].first + x;
            c1 = mp[make_pair(x - y, x - z)].second;
            c2 = i;
        }
    }
    
    if (ans == -1e9) {
        puts("Impossible");
    } else {
        for (i = 0; i < (n + 1) / 2; i++) {
            if (c1 % 3 == 0) {
                puts("MW");
            } else if (c1 % 3 == 1) {
                puts("LW");
            } else {
                puts("LM");
            }
            
            c1 /= 3;
        }
        
        for (i = 0; i < n / 2; i++) {
            if (c2 % 3 == 0) {
                puts("MW");
            } else if (c2 % 3 == 1) {
                puts("LW");
            } else {
                puts("LM");
            }
            
            c2 /= 3;
        }
    }
    
    return 0;
}