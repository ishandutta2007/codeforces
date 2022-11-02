#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[4000][3];
int f[4000];
long long sum[4000];

int main()
{
    int n, i, j;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    
    for (i = 0; i < n; i++) {
        long long x = 0;
        
        if (f[i] == 1) continue;
        
        v.push_back(i);
        
        x += a[i][0];
        
        for (j = i + 1; j < n && x > 0; j++) {
            if (f[j] == 1) continue;
            
            sum[j] += x;
            
            x--;
        }
        
        x = 0;
        
        for (j = i + 1; j < n; j++) {
            if (f[j] == 1) continue;
            
            sum[j] += x;
            
            if (sum[j] > a[j][2]) {
                f[j] = 1;
                x += a[j][1];
            }
        }
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", v[i] + 1);
    }
    
    puts("");
    
    return 0;
}