#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[1000];

int dfs(int x, vector <pair<int, int> > &v)
{
    int i, j, k;
    vector <int> w;
    
    if (a[0] != 1) w.push_back(0);
    
    for (i = 0; i < n - 1; i++) {
        if (abs(a[i] - a[i + 1]) != 1) w.push_back(i + 1);
    }
    
    if (a[n - 1] != n) w.push_back(n);
    
    if (w.size() == 0) return 1;
    
    if (w.size() > x * 2) return 0;
    
    for (i = 0; i < w.size(); i++) {
        for (j = i + 1; j < w.size(); j++) {
            if (w[j] == w[i] + 1) continue;
            
            for (k = 0; k < (w[j] - w[i]) / 2; k++) {
                swap(a[w[i] + k], a[w[j] - k - 1]);
            }
            
            if (dfs(x - 1, v) == 1) {
                v.push_back(make_pair(w[i] + 1, w[j]));
                
                return 1;
            }
            
            for (k = 0; k < (w[j] - w[i]) / 2; k++) {
                swap(a[w[i] + k], a[w[j] - k - 1]);
            }
        }
    }
    
    if (x == 3) {
        for (i = 0; i < n - 1; i++) {
            if (abs(a[i] - a[i + 1]) != 1) continue;
            
            if (i > 0 && abs(a[i] - a[i - 1]) == 1) continue;
            if (i < n - 2 && abs(a[i + 1] - a[i + 2]) == 1) continue;
            
            w.push_back(i + 1);
        }
        
        sort(w.begin(), w.end());
        
        for (i = 0; i < w.size(); i++) {
            for (j = i + 1; j < w.size(); j++) {
                for (k = 0; k < (w[j] - w[i]) / 2; k++) {
                    swap(a[w[i] + k], a[w[j] - k - 1]);
                }
                
                if (dfs(x - 1, v) == 1) {
                    v.push_back(make_pair(w[i] + 1, w[j]));
                    
                    return 1;
                }
                
                for (k = 0; k < (w[j] - w[i]) / 2; k++) {
                    swap(a[w[i] + k], a[w[j] - k - 1]);
                }
            }
        }
    }
    
    return 0;
}

int main()
{
    int i;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    dfs(3, v);
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}