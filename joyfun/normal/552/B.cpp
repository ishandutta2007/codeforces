#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

ll n;

int main() {
    cin >> n;
    ll s = 1;
    ll ans = 0;
    ll cnt = 1;
    while (s * 10 <= n) {
        ans += (s * 10 - s) * cnt;
        s *= 10;
        cnt++;
    }
    ans += (n - s + 1) * cnt;
    cout << ans << endl;
    return 0;
}