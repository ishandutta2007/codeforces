#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
    int n, m, s, l, r, mid, i, j, k;
    vector <pair<int, int> > v;
    vector <pair<int, pair<int, int> > > w;
    priority_queue <pair<int, int> > q;
    
    scanf("%d %d %d", &n, &m, &s);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        w.push_back(make_pair(x, make_pair(0, i)));
    }
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        w[i].second.first = x;
    }
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    for (i = 0; i < n; i++) {
        if (w[i].first >= v.back().first && w[i].second.first <= s) break;
    }
    
    if (i == n) {
        puts("NO");
        
        return 0;
    }
    
    puts("YES");
    
    l = 0, r = m, mid = (l + r) / 2;
    
    while (r - l > 1) {
        int f = 0;
        long long sum = 0;
        priority_queue <int> q;
        
        for (i = n - 1, j = m - 1; i >= 0 && j >= 0;) {
            if (v[j].first <= w[i].first) {
                q.push(-w[i].second.first);
                
                i--;
            } else if (q.empty()) {
                f = 1;
                
                break;
            } else {
                sum -= q.top();
                
                q.pop();
                
                j -= mid;
            }
        }
        
        if (f == 0 && j >= 0) {
            while (j >= 0 && !q.empty()) {
                sum -= q.top();
                
                q.pop();
                
                j -= mid;
            }
            
            if (j >= 0) f = 1;
        }
        
        if (f == 0 && sum <= s) {
            r = mid;
            mid = (l + r) / 2;
        } else {
            l = mid;
            mid = (l + r) / 2;
        }
    }
    
    for (i = n - 1, j = m - 1; i >= 0 && j >= 0;) {
        if (v[j].first <= w[i].first) {
            q.push(make_pair(-w[i].second.first, w[i].second.second));
            
            i--;
        } else {
            int x = q.top().second;
            
            q.pop();
            
            for (k = 0; k < r; k++) {
                if (j - k < 0) break;
                
                a[v[j - k].second] = x + 1;
            }
            
            j -= r;
        }
    }
    
    if (j >= 0) {
        while (j >= 0) {
            int x = q.top().second;
            
            q.pop();
            
            for (k = 0; k < r; k++) {
                if (j - k < 0) break;
                
                a[v[j - k].second] = x + 1;
            }
            
            j -= r;
        }
    }
    
    for (i = 0; i < m; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}