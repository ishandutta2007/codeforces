#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main(){
    int x, y, l, r;
    cin >> l >> r >> x >> y;
    int a1b1 = y * x;
    int ans = 0;
    for (int i = x; i <= sqrt(a1b1); i += x){
        if (a1b1 % i == 0){
            if (__gcd(i, a1b1 / i) == x){
                if (i >= l && a1b1 / i <= r){
                    ans++;
                    if (i != a1b1 / i){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}