#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;





int main() {
    ios_base::sync_with_stdio(false);
    ll n, t, k, d;
    cin >> n >> t >> k >> d;
    if(k * (d / t + 1) >= n){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }



    return 0;
}