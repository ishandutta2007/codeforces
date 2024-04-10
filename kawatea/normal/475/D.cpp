#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int a[100000];

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, q, i, j;
    vector <pair<int, int> > v;
    map <int, long long> mp;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int g = a[i];
        vector <pair<int, int> > w;
        
        w.push_back(make_pair(g, i + 1));
        
        for (j = 0; j < v.size(); j++) {
            int ng = gcd(g, v[j].first);
            
            if (ng != g) {
                g = ng;
                w.push_back(make_pair(g, v[j].second));
            }
        }
        
        for (j = 0; j + 1 < w.size(); j++) mp[w[j].first] += w[j].second - w[j + 1].second;
        
        mp[w.back().first] += w.back().second;
        
        v = w;
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x;
        
        scanf("%d", &x);
        
        printf("%I64d\n", mp[x]);
    }
    
    return 0;
}