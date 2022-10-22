#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main() {
    int n, p;
    cin >> n >> p;
    int ans = -1;
    for (int i = 1; i < 30; i++) {
        int k = n - p * i, z = k;
        int res = 0;
        while (k > 0) {
            if (k % 2) {
                res++;
            }
            k /= 2;
        }
        if (res <= i && z >= i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}