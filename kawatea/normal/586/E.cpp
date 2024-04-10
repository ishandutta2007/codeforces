#include <cstdio>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int i;
    long long x, y;
    vector <pair<long long, int> > v;
    
    scanf("%I64d %I64d", &x, &y);
    
    if (gcd(x, y) > 1) {
        puts("Impossible");
        
        return 0;
    }
    
    while (x != y) {
        if (x == 1) {
            v.push_back(make_pair(y - 1, 1));
            
            break;
        } else if (y == 1) {
            v.push_back(make_pair(x - 1, 0));
            
            break;
        } else if (x > y) {
            v.push_back(make_pair(x / y, 0));
            
            x %= y;
        } else {
            v.push_back(make_pair(y / x, 1));
            
            y %= x;
        }
    }
    
    for (i = 0; i < v.size(); i++) {
        if (v[i].second == 0) {
            printf("%I64dA", v[i].first);
        } else {
            printf("%I64dB", v[i].first);
        }
    }
    
    puts("");
    
    return 0;
}