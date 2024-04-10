#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[100001];

int main()
{
    int n, i, j;
    vector <pair<int, int> > w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[x].push_back(i);
    }
    
    for (i = 1; i <= 100000; i++) {
        if (v[i].size() == 0) continue;
        
        if (v[i].size() == 1) {
            w.push_back(make_pair(i, 0));
        } else {
            int x = v[i][1] - v[i][0];
            
            for (j = 2; j < v[i].size(); j++) {
                if (v[i][j] - v[i][j - 1] != x) break;
            }
            
            if (j == v[i].size()) w.push_back(make_pair(i, x));
        }
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) printf("%d %d\n", w[i].first, w[i].second);
    
    return 0;
}