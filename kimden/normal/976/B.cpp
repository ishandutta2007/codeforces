#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    if(k <= n - 1){
        cout << k + 1 << " " << 1 << endl;
        return 0;
    }
    k -= n;
    ll x = n;
    x -= 2 * (k / (2 * (m - 1)));
    k %= (2 * (m - 1));
    ll y = 2;
    if(k >= m - 1){
        k -= m - 1;
        y = m;
        --x;
        y -= k;
    }else{
        y += k;
    }
    cout << x << " " << y << endl;
}