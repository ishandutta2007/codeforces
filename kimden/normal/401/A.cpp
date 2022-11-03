#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ll n, x;
    cin >> n >> x;
    ll y, sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> y;
        sum += y;
    }
    cout << (abs(sum) + x - 1) / x << endl;
    return 0;
}