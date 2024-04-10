#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a[100000];
int b[100001];
int c[100001];
int dp[1001];

int main()
{
    int n, i, j;
    vector <int> v;
    vector <pair<int, int> > w;
    queue <int> q;
    
    b[0] = b[1] = 1;
    
    for (i = 2; i <= 100000; i++) {
        if (b[i] == 0) {
            v.push_back(i);
            
            if (i < 1000) {
                dp[i - 1] = i - 1;
                q.push(i - 1);
            }
            
            for (j = i * 2; j <= 100000; j += i) b[j] = 1;
        }
    }
    
    while (!q.empty()) {
        int x = q.front();
        
        q.pop();
        
        for (i = 0; i < v.size(); i++) {
            if (x + v[i] - 1 > 1000) break;
            
            if (dp[x + v[i] - 1] == 0) {
                dp[x + v[i] - 1] = v[i] - 1;
                q.push(x + v[i] - 1);
            }
        }
    }
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) c[a[i]] = i;
    
    for (i = 0; i < n; i++) {
        int x = c[i + 1];
        
        if (x - i >= 1000) {
            int y = v[upper_bound(v.begin(), v.end(), x - i + 1) - v.begin() - 1] - 1;
            
            swap(a[x - y], a[x]);
            swap(c[a[x - y]], c[a[x]]);
            
            w.push_back(make_pair(x - y, x));
            x -= y;
        }
        
        while (x > i) {
            int y = dp[x - i];
            
            swap(a[x - y], a[x]);
            swap(c[a[x - y]], c[a[x]]);
            
            w.push_back(make_pair(x - y, x));
            x -= y;
        }
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) printf("%d %d\n", w[i].first + 1, w[i].second + 1);
    
    return 0;
}