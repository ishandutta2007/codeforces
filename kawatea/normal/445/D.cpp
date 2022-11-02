#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x;
int a[100000];
int b[100000];
int c[100000];

int next(void)
{
    x = ((long long)x * 37 + 10007) % 1000000007;
    
    return x;
}

int main()
{
    int n, d, i, j;
    
    scanf("%d %d %d", &n, &d, &x);
    
    for (i = 0; i < n; i++) a[i] = i + 1;
    for (i = 0; i < n; i++) swap(a[i], a[next() % (i + 1)]);
    
    for (i = 0; i < n; i++) {
        if (i < d) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
    for (i = 0; i < n; i++) swap(b[i], b[next() % (i + 1)]);
    
    if (d < 1000) {
        vector <int> v;
        
        for (i = 0; i < n; i++) {
            if (b[i] == 1) v.push_back(i);
        }
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < v.size(); j++) {
                if (v[j] > i) break;
                
                c[i] = max(c[i], a[i - v[j]]);
            }
        }
    } else {
        vector <pair<int, int> > v;
        
        for (i = 0; i < n; i++) v.push_back(make_pair(a[i], i));
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (v[j].second <= i && b[i - v[j].second] == 1) {
                    c[i] = v[j].first;
                    
                    break;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) printf("%d\n", c[i]);
    
    return 0;
}