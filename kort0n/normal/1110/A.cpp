#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll b, k;
    cin >> b >> k;
    ll sum = 0;
    ll a[100500];
    for(int i = 1; i <= k; i++) {
        ll in;
        cin >> a[i];
        sum += (a[i] % 2);
    }
    if(b % 2 == 0) {
        if(a[k] % 2 == 0) cout << "even" << endl;
        else cout << "odd" << endl;
        return 0;
    }
    if(sum % 2 == 0) cout << "even" << endl;
    else cout << "odd" << endl;
    return 0;
}