#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m = 1000000007;
int a[100001];
long long b[100001];
long long inv[100001];
long long fact[100001];
long long invfact[100001];

long long comb(int x, int y) {
    return fact[x] * invfact[y] % m * invfact[x - y] % m;
}

int main()
{
    int n, l, r, p, i;
    long long ans = 1;
    vector <pair<int, int> > v;
    
    b[0] = 1;
    
    for (i = 1; i <= 100000; i++) b[i] = b[i - 1] * 2 % m;
    
    inv[1] = 1;
    
    for (i = 2; i <= 100000; i++) inv[i] = inv[m % i] * (m - m / i) % m;
    
    fact[0] = invfact[0] = 1;
    
    for (i = 1; i <= 100000; i++) fact[i] = fact[i - 1] * i % m;
    for (i = 1; i <= 100000; i++) invfact[i] = invfact[i - 1] * inv[i] % m;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x > 0) {
            a[i + 1]++;
            v.push_back(make_pair(x, i));
        }
    }
    
    for (i = 1; i <= n; i++) a[i] += a[i - 1];
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    if (v.size() == 0) {
        printf("%d\n", (int)b[n - 1]);
        
        return 0;
    }
    
    l = 0, r = n, p = n + 1;
    
    for (i = 0; i < v.size(); i++) {
        int x = v[i].second - l + 1;
        int y = r - v[i].second;
        int z = p - v[i].first;
        
        if (x > z && y > z) {
            ans = 0;
            
            break;
        }
        
        if (i + 1 == v.size()) {
            if (v[i].first == 1) {
                ans = ans * comb(z - 1, x - 1) % m;
            } else {
                long long sum = 0;
                
                if (x <= z) sum = (sum + ans * comb(z - 1, x - 1) % m) % m;
                if (y <= z) sum = (sum + ans * comb(z - 1, y - 1) % m) % m;
                
                ans = sum * b[v[i].first - 2] % m;
            }
        } else {
            if (a[v[i].second] - a[l] > 0 && a[r] - a[v[i].second + 1] > 0) {
                ans = 0;
                
                break;
            }
            
            if (a[v[i].second] - a[l] == 0 && x <= z && a[r] - a[r - z + x] == 0) {
                ans = ans * comb(z - 1, x - 1) % m;
                
                l += x;
                r -= z - x;
            } else if (a[r] - a[v[i].second + 1] == 0 && y <= z && a[l + z - y] - a[l] == 0) {
                ans = ans * comb(z - 1, y - 1) % m;
                
                l += z - y;
                r -= y;
            } else {
                ans = 0;
                
                break;
            }
        }
        
        p = v[i].first;
    }
    
    printf("%d\n", (int)ans);
    
    return 0;
}