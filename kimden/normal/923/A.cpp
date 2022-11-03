#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, ans, lp[1001005];

void brute(int x, int iter) {
    if (iter == 0) {
        ans = min(ans, x);
        return;
    }
    if (lp[x] == x)
        return;
    int cur = x;
    while (cur > 1) {
        int pr = lp[cur];
        while (cur % pr == 0)
            cur /= pr;
        int L = max(pr + 1, x - pr + 1), R = (iter == 1 ? L : x);
        for (; L <= R; ++L)
            brute(L, iter - 1);
    }
}

int main() {
    for (int i = 1; i < 1001005; ++i)
        lp[i] = i;
    for (int i = 2; i * i < 1001005; ++i)
        if (lp[i] == i)
            for (int j = i * i; j < 1001005; j += i)
                if (lp[j] > i)
                    lp[j] = i;

    ios_base::sync_with_stdio(false);
    cin >> n;
    ans = n;
    brute(ans, 2);
    cout << ans << endl;
}