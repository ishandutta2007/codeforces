#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int a[200000];
int b[7001][2];

int main()
{
    int n, m, i, j;
    vector <pair<int, pair<int, pair<int, int> > > > w;
    
    for (i = 1; i < 200000; i++) a[i] = i + 32 - __builtin_clz(i);
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int q;
        
        scanf("%d", &q);
        
        if (q == 1) {
            int t, l, r, x;
            
            scanf("%d %d %d %d", &t, &l, &r, &x);
            
            w.push_back(make_pair(t, make_pair(l, make_pair(r, x))));
        } else {
            int t, v;
            set <int> s;
            
            scanf("%d %d", &t, &v);
            
            b[t][0] = b[t][1] = v;
            
            for (j = t + 1; j <= n; j++) {
                b[j][0] = a[b[j - 1][0] - 1] + 1;
                b[j][1] = a[b[j - 1][1]];
            }
            
            for (j = 0; j < w.size(); j++) {
                if (w[j].first >= t) {
                    int x1 = w[j].second.first;
                    int y1 = w[j].second.second.first;
                    int x2 = b[w[j].first][0];
                    int y2 = b[w[j].first][1];
                    
                    if ((x1 >= x2 && x1 <= y2) || (y1 >= x2 && y1 <= y2) || (x1 <= x2 && y1 >= y2)) s.insert(w[j].second.second.second);
                }
            }
            
            printf("%d\n", s.size());
        }
    }
    
    return 0;
}