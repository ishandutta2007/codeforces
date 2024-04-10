#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (3e5);

int nbValues;

int Ask(int guess) {
    printf("? %lld", guess);
    cout << endl;
    int ans;
    scanf("%lld", &ans);
    return ans;
}

int Dicho() {
    int pos = 0;
    for (int bit = (1 << 21); bit; bit >>= 1)
    {
        if (Ask(pos + bit) != 1)
            pos += bit;
    }
    return ++ pos;
}

void Solve() {
    scanf("%lld", &nbValues);
    int tot = Dicho();
    int best = tot;
    for (int k = 2; k <= nbValues; k ++)
    {
        if (Ask(tot / k) == k)
        best = min(best, k * (tot / k));
    }
    printf("! %lld", best);
    cout << endl;
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}