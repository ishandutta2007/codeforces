#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[200000];
int b[100001][2];
int sum[200001];
vector <int> v[100000];

int main()
{
    int n, x = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        if (a[i] > 0) {
            if (a[i] < x) {
                puts("-1");
                
                return 0;
            }
            
            x = max(x, a[i]);
            
            v[a[i] - 1].push_back(i);
            
            if (v[a[i] - 1].back() - v[a[i] - 1][0] >= 5) {
                puts("-1");
                
                return 0;
            }
            
            sum[i + 1]++;
        }
        
        sum[i + 1] += sum[i];
    }
    
    for (i = 1; i <= 100000; i++) b[i][0] = b[i][1] = -1;
    
    for (i = 0; i < 100000; i++) {
        int x, y;
        
        if (b[i][0] == -1) break;
        
        x = b[i][0] + 2;
        y = min(b[i][1] + 5, n);
        
        if (x > n) break;
        
        if (v[i].size() > 0) x = max(x, v[i].back() + 1);
        
        if (x > y) {
            puts("-1");
            
            return 0;
        }
        
        while (sum[y] - sum[x] != 0) y--;
        
        if (x > y) {
            puts("-1");
            
            return 0;
        }
        
        if (sum[y] != sum[b[i][0]] + v[i].size()) break;
        
        b[i + 1][0] = x;
        b[i + 1][1] = y;
    }
    
    for (i = 100000; i >= 0; i--) {
        if (b[i][1] == n) break;
    }
    
    if (i < 0) {
        puts("-1");
        
        return 0;
    }
    
    printf("%d\n", i);
    
    x = n;
    
    for (; i > 0; i--) {
        for (j = 2; j <= 5; j++) {
            if (b[i - 1][0] <= x - j && b[i - 1][1] >= x - j) break;
        }
        
        for (; j > 0; j--) a[--x] = i;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}