#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int left_, right_;

void Solve() {
    scanf("%lld %lld", &left_, &right_);
    left_ --;
    int ans = right_ - left_;
    
    for (int bit = 0; bit < 20; bit ++)
    {
        int curBit = (1 << bit);
        int b = 0;
        int a = right_ - (right_ % (curBit << 1));
        if (right_ & curBit)
            b += (right_ % curBit) + 1;
        b += a >> 1;
        a = left_ - (left_ % (curBit << 1));
        if (left_ & curBit)
            b -= (left_ % curBit + 1);
        b -= a >> 1;
        ans = min(ans, right_ - left_ - b);
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}