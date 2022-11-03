#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;





int main() {
    int n, k;
    cin >> n >> k;
    int a = 0;
    int cyc = 0;
    ll ans = 1;
    if(k > n / 2){
        k = n - k;
    }
    for(int i = 0; i < n; i++){
        if(i){
            cout << " ";
        }
        a += k;
        if(a >= n){
            a -= n;
            cyc++;
        }
        if(cyc > 0 && a < k){
            ans += (2 * cyc);
        }else if(cyc > 0){
            ans += 2 * cyc + 1;
        }else {
            ans += 1;
        }
        if(a == 0){
            ans--;
        }
        cout << ans;
    }
    cout << endl;
    return 0;
}