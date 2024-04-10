#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char s[1000001];
int ans[1000000];
long long bit[1000001];

long long sum(int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    
    return s;
}

void add(int i, long long v)
{
    while (i <= 1000000) {
        bit[i] += v;
        i += i & -i;
    }
}

int main()
{
    int n, m, i;
    vector <int> v;
    vector <pair<int, pair<int, int> > > w;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            v.push_back(i);
        } else if (v.size() > 0) {
            add(i + 1, 1);
            w.push_back(make_pair(v.back() + 2, make_pair(-1, i + 1)));
            
            v.pop_back();
        }
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        w.push_back(make_pair(x, make_pair(i, y)));
    }
    
    sort(w.begin(), w.end());
    
    for (i = 0; i < w.size(); i++) {
        if (w[i].second.first == -1) {
            add(w[i].second.second, -1);
        } else {
            ans[w[i].second.first] = sum(w[i].second.second) * 2;
        }
    }
    
    for (i = 0; i < m; i++) printf("%d\n", ans[i]);
    
    return 0;
}