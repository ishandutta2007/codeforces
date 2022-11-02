#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int> > v, w;

int main()
{
    int n, p, q, x = 0, y = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        if (x == 0) {
            v.push_back(make_pair(y, i + 1));
        } else {
            w.push_back(make_pair(y, i + 1));
        }
    }
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    p = v.size() - 1;
    q = w.size() - 1;
    
    while (1) {
        if (p == -1 || q == -1) break;
        
        printf("%d %d %d\n", v[p].second, w[q].second, min(v[p].first, w[q].first));
        
        if (v[p].first < w[q].first || (v[p].first == w[q].first && p > q)) {
            w[q].first -= v[p].first;
            
            p--;
        } else {
            v[p].first -= w[q].first;
            
            q--;
        }
    }
    
    return 0;
}