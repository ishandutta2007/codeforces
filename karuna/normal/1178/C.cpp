#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;
int w, h;

ll pow(ll a, ll x) {
    ll ret=1;
    while (x) {
        if (x%2==1) {
            ret = (ret*a)%mod;
        }
        x/=2;
        a = (a*a)%mod;
    }

    return ret;
}

int main() {
    cin >> w >> h;

    cout << pow(2LL, ll(w+h));
}