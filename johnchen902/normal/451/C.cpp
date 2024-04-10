#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool ok(long long n, long long k, long long d1, long long d2, long long a, long long b, long long c) {
    if(a < 0 || b < 0 || c < 0) return false;
    if(d1 != abs(a - b)) return false;
    if(d2 != abs(b - c)) return false;
    if(k != a + b + c) return false;
    return n >= 3 * max(a, max(b, c));
}

bool solve(long long n, long long k, long long d1, long long d2) {
    if(n % 3)
        return false;
    for(int a : {+1, -1})
        for(int b : {+1, -1}) {
            // (x +- d1) (x) (x +- d2)
            long long x = (k - a * d1 - b * d2) / 3;
            if(ok(n, k, d1, d2, x + a * d1, x, x + b * d2))
                return true;
        }
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        long long n, k, d1, d2;
        scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
        puts(solve(n, k, d1, d2) ? "yes" : "no");
    }
}