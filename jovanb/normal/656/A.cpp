#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int a;
    cin >> a;
    if(a <= 12){
        ll k = pow(2, a);
        cout << k;
        return 0;
    }
    a -= 13;
    ll res = 8092;
    while(a--) res *= 2;
    cout << res;
    return 0;
}