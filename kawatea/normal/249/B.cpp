#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[500001];

int main()
{
    int n, t, c = 0, l, r, m, i;
    vector <pair<int, int> > v;
    
    scanf("%d %d", &n, &t);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'H') {
            v.push_back(make_pair(i, 0));
            c = i;
        } else if (s[i] == 'S') {
            v.push_back(make_pair(i, 1));
        }
    }
    
    if (c + 1 > t) {
        puts("-1");
        
        return 0;
    }
    
    l = -1, r = v.size() + 1, m = (l + r) / 2;
    
    while (r - l > 1) {
        int p = m, q, x, sum = 0;
        vector <pair<int, int> > w;
        
        for (i = 0; i < v.size(); i++) {
            if (v[i].second == 1) {
                p++;
                
                if (p == 0) {
                    sum += (v[i].first - q) * 2;
                    
                    x = v[i].first;
                }
            } else {
                p--;
                
                if (p == -1) {
                    q = v[i].first;
                    
                    w.push_back(make_pair(sum, q));
                }
                
                x = v[i].first;
            }
        }
        
        sum += x + 1;
        
        for (i = 0; i < w.size(); i++) sum = min(sum, w[i].first + x + 1 + x - w[i].second);
        
        if (p < 0 || sum > t) {
            l = m;
            m = (l + r) / 2;
        } else {
            r = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%d\n", r);
    
    return 0;
}