#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

int main() {
    ios :: sync_with_stdio(0);
    LL l, r, k, _ = 0;
    cin >> l >> r >> k;
    if(k == 1) {
        cout << (l <= 1 && 1 <= r ? 1 : -1) << endl;
        return 0;
    }
    LL now = 1;
    for(; now <= r; now *= k) {
        if(now >= l) {
            _ = 1;
            cout << now << ' ';
        }
        if((double)now * k > 1e19) break ;
    }
    if(_ == 0) cout << -1;
    cout << endl;
    return 0;
}