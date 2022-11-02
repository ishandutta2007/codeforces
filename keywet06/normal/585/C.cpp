#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

vector<int64> ans;

int64 gcd(int64 x, int64 y) {
    while (true) {
        if (x == y) return x;
        if (x < y) {
            int64 p = (y - 1) / x;
            ans.push_back(-p);
            y -= x * p;
        } else {
            int64 p = (x - 1) / y;
            ans.push_back(p);
            x -= y * p;
        }
    }
    throw;
}

int main() {
    int64 x, y;
    cin >> x >> y;
    if (gcd(x, y) != 1) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld%c", abs(ans[i]), (ans[i] > 0 ? 'A' : 'B'));
    }
    printf("\n");
    return 0;
}