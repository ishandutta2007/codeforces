#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int p, k;
    cin >> p >> k;
    if(k == 0){
        ll res = 1;
        for(int i=1; i<p; i++){
            res *= p;
            res %= MOD;
        }
        cout << res;
        return 0;
    }
    if(k == 1){
        ll res = 1;
        for(int i=1; i<=p; i++){
            res *= p;
            res %= MOD;
        }
        cout << res;
        return 0;
    }
    int x = 0;
    ll r = 1;
    while(1){
        x++;
        r *= k;
        r %= p;
        if(r == 1) break;
    }
    x = (p-1)/x;
    ll res = 1;
    for(int i=1; i<=x; i++){
        res *= p;
        res %= MOD;
    }
    cout << res;
    return 0;
}