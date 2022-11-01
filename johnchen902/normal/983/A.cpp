#include <cstdio>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;
static_assert(sizeof(long long) >= 8);
map<tuple<long long, long long, long long>, int> mem;
bool solve(long long p, long long q, long long b) {
    q /= __gcd(p, q);
    while (q != 1) {
        long long div = __gcd(b, q);
        if (div == 1)
            return false;
        do
            q /= div;
        while (q % div == 0);
    }
    return true;
}
bool mem_solve(long long p, long long q, long long b) {
    int &ref = mem[make_tuple(p, q, b)];
    if (!ref)
        ref = solve(p, q, b) + 1;
    return ref - 1;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        long long p, q, b;
        scanf("%lld %lld %lld", &p, &q, &b);
        puts(mem_solve(p, q, b) ? "Finite" : "Infinite");
    }
}