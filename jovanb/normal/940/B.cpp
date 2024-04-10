#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll res = 0;
    if(k == 1){
        cout << (n-1)*a;
        return 0;
    }
    while(n > 1){
        if(n < k){
            res += (n-1)*a;
            break;
        }
        else if(n%k == 0){
            res += min(b, (n-n/k)*a);
            n = n/k;
        }
        else{
            res += a*(n%k);
            n -= n%k;
        }
    }
    cout << res;
    return 0;
}