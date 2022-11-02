#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[100001];

long long modpow(long long x, long long y, long long m)
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
    int n, m = 1000000007, i, j;
    long long sum = 1;
    vector <int> w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        w.push_back(x);
    }
    
    for (i = 1; i <= 100000; i++) {
        for (j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                v[i].push_back(j);
                
                if (j != i / j) v[i].push_back(i / j);
            }
        }
        
        sort(v[i].begin(), v[i].end());
    }
    
    sort(w.begin(), w.end());
    
    for (i = 2; i <= 100000; i++) {
        int p = 0;
        long long x, y, z = 1;
        
        if (w[w.size() - 1] < i) break;
        
        for (j = 1; j < v[i].size(); j++) {
            int q = lower_bound(w.begin(), w.end(), v[i][j]) - w.begin();
            
            z = z * modpow(j, q - p, m) % m;
            
            p = q;
        }
        
        x = modpow(v[i].size(), w.size() - p, m);
        y = modpow(v[i].size() - 1, w.size() - p, m);
        
        z = z * ((x - y + m) % m) % m;
        
        sum = (sum + z) % m;
    }
    
    printf("%d\n", (int)sum);
    
    return 0;
}