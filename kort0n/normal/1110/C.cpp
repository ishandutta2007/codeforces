#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll q;
    cin >> q;
    while(q--) {
        ll in;
        cin >> in;
        ll ans = 2;
        while(in >= ans) ans *= 2;
        ans--;
        if(ans == in) {
            bool flag = true;
            for(ll i = 2; i * i <= in; i++) {
                if(in % i == 0) {
                    cout << in / i << endl;
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << 1 << endl;
            }
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}