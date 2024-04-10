#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1 << 11][24];

int main()
{
    int n, c = 0, i, j, k, l;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) {
        if (v[i] == 1) c++;
        if (v[i] == 2) {
            puts("NO");
            
            return 0;
        }
    }
    
    if (n - c > 11 || v[n - 1] != n) {
        puts("NO");
        
        return 0;
    }
    
    if (n == 1) {
        puts("YES");
        
        return 0;
    }
    
    dp[0][c] = 1;
    
    for (i = c; i < n; i++) {
        int x = i - c;
        
        for (j = 0; j < (1 << x); j++) {
            for (k = 0; k <= c; k++) {
                int y = j;
                
                if (dp[j][k] == 0) continue;
                
                do {
                    int sum = 1;
                    
                    for (l = 0; l < x; l++) {
                        if ((y >> l) & 1) {
                            if (v[l + c] == v[i] - 1) break;
                            
                            sum += v[l + c];
                        }
                    }
                    
                    if (l == x && sum <= v[i] && sum + k >= v[i]) dp[(j ^ y) | (1 << x)][k - v[i] + sum] = 1;
                    
                    y = (y - 1) & j;
                } while (y != j);
            }
        }
    }
    
    if (dp[1 << (n - c - 1)][0] == 1) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}