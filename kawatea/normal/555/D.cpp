#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[200000];

int main()
{
    int n, m, i;
    vector <int> v1, v2;
    map <int, int> mp;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[i] = x;
        v1.push_back(x);
        v2.push_back(-x);
        mp[x] = i + 1;
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for (i = 0; i < m; i++) {
        int x, y, f = 0;
        
        scanf("%d %d", &x, &y);
        
        x = a[x - 1];
        
        while (1) {
            int x1 = *lower_bound(v1.begin(), v1.end(), x - y);
            int x2 = - *lower_bound(v2.begin(), v2.end(), -x - y);
            
            if (x == x1 && x == x2) break;
            
            if (f == 0) {
                if (x2 == x) {
                    f = 1;
                } else {
                    int p = x2 - x;
                    int x3 = *lower_bound(v1.begin(), v1.end(), x2 - (y - p));
                    
                    if (x3 == x) {
                        if (y / p % 2 == 1) {
                            x = x2;
                            f = 1;
                        }
                        
                        y %= p;
                    } else if (x3 == x2) {
                        x = x2;
                        break;
                    } else {
                        x = x2;
                        y -= p;
                        f = 1;
                    }
                }
            } else {
                if (x1 == x) {
                    f = 0;
                } else {
                    int p = x - x1;
                    int x3 = - *lower_bound(v2.begin(), v2.end(), -x1 - (y - p));
                    
                    if (x3 == x) {
                        if (y / p % 2 == 1) {
                            x = x1;
                            f = 0;
                        }
                        
                        y %= p;
                    } else if (x3 == x1) {
                        x = x1;
                        break;
                    } else {
                        x = x1;
                        y -= p;
                        f = 0;
                    }
                }
            }
        }
        
        printf("%d\n", mp[x]);
    }
    
    return 0;
}