#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int a, n, i, j;
    long long ans = 0;
    char s[4001];
    int sum[4001] = {0};
    vector <int> v;
    map <int, long long> mp;
    
    scanf("%d", &a);
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i] - '0';
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            mp[sum[j + 1] - sum[i]]++;
        }
    }
    
    if (a == 0) {
        long long sum = n * (n + 1) / 2;
        
        printf("%I64d\n", mp[0] * (sum - mp[0]) * 2 + mp[0] * mp[0]);
        
        return 0;
    }
    
    for (i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            v.push_back(i);
            
            if (a / i != i) v.push_back(a / i);
        }
    }
    
    for (i = 0; i < v.size(); i++) ans += mp[v[i]] * mp[a / v[i]];
    
    printf("%I64d\n", ans);
    
    return 0;
}