#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char s[100001];
int sum[3][100001];

int main()
{
    int n, m, i, j;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        sum[s[i] - 'x'][i + 1]++;
        
        for (j = 0; j < 3; j++) sum[j][i + 1] += sum[j][i];
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        vector <int> v;
        
        scanf("%d %d", &x, &y);
        
        if (y - x < 2) {
            puts("YES");
            
            continue;
        }
        
        for (j = 0; j < 3; j++) v.push_back(sum[j][y] - sum[j][x - 1]);
        
        sort(v.begin(), v.end());
        
        if (v[2] <= v[0] + 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    
    return 0;
}