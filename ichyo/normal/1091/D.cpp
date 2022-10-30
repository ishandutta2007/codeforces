#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

int main(){
    iostream_init();
    LL n;
    cin >> n;
    LL MOD = 998244353;
    vector<LL> factor(n + 10);
    factor[0] = 1;
    for (int i = 1; i <= n; i++) {
        factor[i] = factor[i-1] * i % MOD;
    }
    LL answer = 0;
    answer += factor[n];
    LL base = 1;
    for (int i = 0; i + 2 < n; i++) {
        base *= (n - i);
        base %= MOD;
        LL add = base * factor[n - 1 - i] % MOD;
        add = (add + MOD - base) % MOD;
        answer += add;
        if (answer >= MOD) {
            answer -= MOD;
        }
    }
    cout << answer << endl;
    return 0;
}