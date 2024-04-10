#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[26];

char s[100001];

int main()
{
    int n, k, i;
    long long ans = 0;
    vector <int> v;
    
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) a[s[i] - 'A']++;
    
    for (i = 0; i < 26; i++) v.push_back(a[i]);
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; k > 0; i++) {
        if (v[i] >= k) {
            ans += (long long)k * k;
            k = 0;
        } else {
            ans += (long long)v[i] * v[i];
            k -= v[i];
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}