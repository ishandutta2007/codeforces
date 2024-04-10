#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];
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
    int n, k, i;
    long long ans = 0;
    set <int> s, s2;
    set <int>::iterator it, it2;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        a[i]--;
        
        b[a[i]] = i;
    }
    
    for (i = 0; i < k; i++) {
        int x;
        
        scanf("%d", &x);
        
        c[x - 1]++;
    }
    
    s.insert(n);
    s2.insert(1);
    
    for (i = 0; i < n; i++) {
        if (c[i] == 0) {
            it = s.lower_bound(b[i]);
            it2 = s2.lower_bound(-b[i]);
            
            ans += *it + *it2 - 1;
            ans -= sum(*it);
            if (*it2 < 0) ans += sum(-*it2);
            
            add(b[i] + 1, 1);
        } else {
            s.insert(b[i]);
            s2.insert(-b[i]);
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}