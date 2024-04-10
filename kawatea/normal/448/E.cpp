#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> v;
vector <vector <int> > w;
vector <long long> ans;

void dfs(int x, int k)
{
    if (k == 0 || x == 0) {
        ans.push_back(v[x]);
    } else {
        int i;
        
        for (i = 0; i < w[x].size(); i++) {
            dfs(w[x][i], k - 1);
            
            if (ans.size() == 100000) return;
        }
    }
}

int main()
{
    long long x, k, i, j;
    
    scanf("%I64d %I64d", &x, &k);
    
    for (i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            
            if (i != x / i) v.push_back(x / i);
        }
    }
    
    sort(v.begin(), v.end());
    
    w.resize(v.size());
    
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j <= i; j++) {
            if (v[i] % v[j] == 0) w[i].push_back(j);
        }
    }
    
    k = min(k, 100000LL);
    
    dfs(v.size() - 1, k);
    
    for (i = 0; i < ans.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", ans[i]);
    }
    
    puts("");
    
    return 0;
}