#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define int
signed rint() {
    signed x; scanf("%d", &x); return x;
}
long long pow(long long a, long long b) { // a, b is small
    long long x = 1;
    while(b--) x *= a;
    return x;
}
long long sdigit(long long x) {
    long long y = 0;
    while(x) y += x % 10, x /= 10;
    return y;
}
signed main(){
    long long a = rint();
    long long b = rint();
    long long c = rint();
    vector<long long> ans;
    for(long long s = 1; s <= 81; s++) {
        long long x = b * pow(s, a) + c;
        if(x < 1000000000 && s == sdigit(x)) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (signed) ans.size());
    for(signed i = 0; i < (signed) ans.size(); i++)
        printf("%d%c", (signed) ans[i], (i == (signed) ans.size() - 1) ? '\n' : ' ');
}