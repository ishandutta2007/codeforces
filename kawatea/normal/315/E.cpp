#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m = 1000000007;
long long bit[100001];

long long sum(int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[i];
        s %= m;
        i -= i & -i;
    }
    
    return s;
}

void add(int i, long long v)
{
    while (i <= n) {
        bit[i] += v;
        bit[i] %= m;
        i += i & -i;
    }
}

int main()
{
    int i;
    long long ans = 0;
    int a[100000];
    int b[100000];
    vector <pair<int, int> > v;
    map <int, long long> mp;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) v.push_back(make_pair(a[i], i));
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) b[v[i].second] = i;
    
    for (i = 0; i < n; i++) {
        long long x = sum(b[i] + 1);
        
        if (!mp.count(a[i])) {
            mp[a[i]] = x;
            
            x++;
        } else {
            x = (x - mp[a[i]] + m) % m;
            
            mp[a[i]] += x;
            mp[a[i]] %= m;
        }
        
        ans += x % m * a[i] % m;
        ans %= m;
        
        add(b[i] + 1, x % m * a[i] % m);
    }
    
    printf("%d\n", (int)ans);
    
    return 0;
}