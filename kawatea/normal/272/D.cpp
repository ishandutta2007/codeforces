#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long fact[200001];

long long mod_pow(long long x, long long y, int m)
{
    long long ans = 1;
    
    while (y) {
        if (y & 1) ans = ans * x % m;
        
        x = x * x % m;
        y >>= 1;
    }
    
    return ans;
}

int main()
{
    int n, m, i, j;
    long long sum = 1, c = 0;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(make_pair(x, i));
    }
    
    scanf("%d", &m);
    
    fact[0] = 1;
    
    for (i = 1; i <= 200000; i++) {
        int x = i;
        
        while (1) {
            if (x & 1) break;
            
            x >>= 1;
        }
        
        fact[i] = fact[i - 1] * x % m;
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        int x, y = 2;
        
        for (j = i; j < v.size(); j++) {
            if (v[i].first != v[j].first) break;
            
            if (j > 0 && v[j].first == v[j - 1].first && v[j].second == v[j - 1].second) c--;
        }
        
        sum = sum * fact[j - i] % m;
        
        x = j - i;
        
        while (y <= x) {
            c += x / y;
            y *= 2;
        }
        
        i = j - 1;
    }
    
    sum = sum * mod_pow(2, c, m) % m;
    
    printf("%d\n", (int)sum);
    
    return 0;
}