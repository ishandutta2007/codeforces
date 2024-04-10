#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

long long l, r;
int k;

vector<long long> solve() {
    if(k >= 4) {
        if(l % 2 == 0)
            return {l, l + 1, l + 2, l + 3}; // got 0
        if(l + 4 < r)
            return {l + 1, l + 2, l + 3, l + 4}; // got 0
    }
    if(k >= 3) {
        long long high = 1LL << 40; static_assert(1LL << 40 >= 1000000000000LL, "small");
        long long ll = l, rr = r - 1;
        for(; high; high >>= 1) {
            if((ll&high) && (rr&high)) break;
            if(!(ll&high) && !(rr&high)) continue;
            if((ll ^ high) <= rr)
                return {ll, high, ll ^ high}; // got 0
            if((ll ^ rr) <= rr)
                return {ll, rr, ll ^ rr}; // got 0
            rr = high - 1;
        }
    }
    if(k >= 2) {
        if(l % 2 == 0)
            return {l, l + 1}; // got 1
        if(l + 2 < r)
            return {l + 1, l + 2}; // got 1
        // even-odd
        if(l < (l ^ (l + 1)))
            return {l};
        else
            return {l, l + 1};
    }
    // k == 1
    return {l};
}

int main(){
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
    scanf("%I64d %I64d %d", &l, &r, &k);
#pragma GCC diagnostic pop
    r++;
    vector<long long> ans = solve();
    long long card = accumulate(ans.begin(), ans.end(), 0LL, bit_xor<long long>());
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
    printf("%I64d\n", card);
#pragma GCC diagnostic pop
    printf("%d\n", (int) ans.size());
    for(int i = 0; i < (int) ans.size(); i++) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
        printf("%I64d", ans[i]);
#pragma GCC diagnostic pop
        putchar(i == (int) ans.size() - 1 ? '\n' : ' ');
    }
}