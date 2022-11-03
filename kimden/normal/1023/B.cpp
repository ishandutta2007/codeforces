#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;



int main() {
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if(n == 1 || k <= 0 || k > 2 * n - 1){
        cout << "0" << endl;
        return 0;
    }
    ll L = max(1LL, k - n);
    ll R = min(n, k - 1);
    ll ans = R - L + 1;
    if(k % 2 == 0){
        --ans;
    }
    ans /= 2;
    cout << ans << endl;



}