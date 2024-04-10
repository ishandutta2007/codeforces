#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, m, i, j;
    long long ans = 0;
    int a[1500][3];
    vector <pair<int, pair<int, pair<int, pair<int, int> > > > > v, w;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        if (x1 == x2) {
            v.push_back(make_pair(0, make_pair(x1, make_pair(0, make_pair(0, min(y1, y2))))));
            w.push_back(make_pair(0, make_pair(x1, make_pair(0, make_pair(0, max(y1, y2))))));
        } else {
            int x = x1 - x2;
            int y = y1 - y2;
            int g;
            int z1, z2;
            
            if (x < 0) {
                x = -x;
                y = -y;
            }
            
            g = gcd(x, abs(y));
            
            x /= g;
            y /= g;
            
            z1 = x;
            z2 = x * y1 - y * x1;
            
            g = gcd(z1, abs(z2));
            
            z1 /= g;
            z2 /= g;
            
            v.push_back(make_pair(x, make_pair(y, make_pair(z1, make_pair(z2, min(x1, x2))))));
            w.push_back(make_pair(x, make_pair(y, make_pair(z1, make_pair(z2, max(x1, x2))))));
        }
    }
    
    for (i = 0; i < m; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            int x = a[i][0] - a[j][0];
            int y = a[i][1] - a[j][1];
            int g;
            int z1, z2;
            int x1, x2, p, q;
            
            if (a[i][2] != a[j][2]) continue;
            
            if (x * x + y * y <= a[i][2] * a[i][2] * 4) continue;
            
            if (y < 0) {
                x = -x;
                y = -y;
            }
            
            x = -x;
            
            if (y == 0) {
                if ((a[i][0] + a[j][0]) % 2 != 0) continue;
                
                p = lower_bound(v.begin(), v.end(), make_pair(0, make_pair((a[i][0] + a[j][0]) / 2, make_pair(0, make_pair(0, a[i][1] + 1))))) - v.begin();
                q = lower_bound(w.begin(), w.end(), make_pair(0, make_pair((a[i][0] + a[j][0]) / 2, make_pair(0, make_pair(0, a[i][1]))))) - w.begin();
                
                ans += p - q;
                
                continue;
            }
            
            g = gcd(abs(x), y);
            
            x /= g;
            y /= g;
            
            z1 = y * 2;
            z2 = y * (a[i][1] + a[j][1]) - x * (a[i][0] + a[j][0]);
            
            g = gcd(z1, abs(z2));
            
            z1 /= g;
            z2 /= g;
            
            if ((a[i][0] + a[j][0]) % 2 == 0) {
                x1 = (a[i][0] + a[j][0]) / 2 + 1;
                x2 = (a[i][0] + a[j][0]) / 2;
            } else if (a[i][0] + a[j][0] > 0) {
                x1 = (a[i][0] + a[j][0]) / 2 + 1;
                x2 = (a[i][0] + a[j][0]) / 2 + 1;
            } else {
                x1 = (a[i][0] + a[j][0]) / 2;
                x2 = (a[i][0] + a[j][0]) / 2;
            }
            
            p = lower_bound(v.begin(), v.end(), make_pair(y, make_pair(x, make_pair(z1, make_pair(z2, x1))))) - v.begin();
            q = lower_bound(w.begin(), w.end(), make_pair(y, make_pair(x, make_pair(z1, make_pair(z2, x2))))) - w.begin();
            
            ans += p - q;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}