#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for(ll i = l; i <= r; i += 2){
        cout << i << " " << i + 1 << endl;
    }
    return 0;
}