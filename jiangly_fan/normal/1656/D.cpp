#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        cin >> n;
        //n=k(k-1)/2+mk
        //n=2^x(2^(x+1)+2m-1)
        LL h = 0;
        while (not ((n >> h) & 1)) h += 1;
        if (n == (1LL << h)) cout << "-1\n";
        else {
            LL k = n >> h;
            if ((__int128)k * (k - 1) / 2 + k <= n) cout << k << "\n";
            else cout << (1LL << (h + 1)) << "\n";
        }
    }
    return 0;
}