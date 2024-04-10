#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll sum = n*(n+1)/2;
        ll mxp = 0;
        while((1LL << (mxp+1)) <= n) mxp++;
        sum -= 2*((1LL << (mxp+1)) - 1);
        cout << sum << "\n";
    }
    return 0;
}