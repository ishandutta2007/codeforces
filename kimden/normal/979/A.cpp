#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ++n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n % 2 == 0){
        n /= 2;
    }
    cout << n << endl;
    return 0;
}