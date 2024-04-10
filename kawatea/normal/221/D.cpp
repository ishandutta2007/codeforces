#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[100001];
int sum[500][100001];

int main()
{
    int n, m, c = 0, i, j;
    vector <int> w;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x > n) continue;
        
        v[x].push_back(i + 1);
    }
    
    for (i = 1; i <= n; i++) {
        if (v[i].size() >= i) {
            for (j = 0; j < v[i].size(); j++) sum[c][v[i][j]]++;
            
            for (j = 1; j <= n; j++) sum[c][j] += sum[c][j - 1];
            
            w.push_back(i);
            
            c++;
        }
    }
    
    for (i = 0; i < m; i++) {
        int l, r, ans = 0;
        
        scanf("%d %d", &l, &r);
        
        for (j = 0; j < c; j++) {
            if(sum[j][r] - sum[j][l - 1] == w[j]) ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}