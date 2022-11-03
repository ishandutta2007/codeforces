#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
using ull = unsigned long long;






int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    n %= 2 * k;
    if(n >= k){
        cout << "YES" << endl;
    }else{

        cout << "NO" << endl;
    }

    return 0;
}