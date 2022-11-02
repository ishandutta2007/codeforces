#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int w, h, n, i;
    set <int> s1, s2;
    multiset <int> s3, s4;
    set <int>::iterator it, it2;
    
    scanf("%d %d %d", &w, &h, &n);
    
    s1.insert(0);
    s1.insert(w);
    s2.insert(0);
    s2.insert(h);
    s3.insert(w);
    s4.insert(h);
    
    for (i = 0; i < n; i++) {
        int x;
        long long p, q;
        char c[2];
        
        scanf("%s %d", c, &x);
        
        if (c[0] == 'V') {
            it = s1.lower_bound(x);
            it2 = it;
            it2--;
            
            s3.erase(s3.find(*it - *it2));
            s3.insert(*it - x);
            s3.insert(x - *it2);
            s1.insert(x);
        } else {
            it = s2.lower_bound(x);
            it2 = it;
            it2--;
            
            s4.erase(s4.find(*it - *it2));
            s4.insert(*it - x);
            s4.insert(x - *it2);
            s2.insert(x);
        }
        
        p = *s3.rbegin();
        q = *s4.rbegin();
        
        printf("%I64d\n", p * q);
    }
    
    return 0;
}