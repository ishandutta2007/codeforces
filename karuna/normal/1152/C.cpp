#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll a, b;
int main() {
    scanf("%lld %lld", &a, &b);
    if (a>b) swap(a, b);
    if (a==b) {
        printf("0");
        return 0;
    }

    ll x = b-a;

    vector<ll> div;
    for (int i=1; i*i<=x; i++) {
        if (x%i==0) div.push_back(i);
    }

    ll mn_lcm = a*b/__gcd(a, b);
    ll mn_k = 0;
    for (auto i : div) {
        ll k = i-b%i;
        if (mn_lcm > (a+k)*(b+k)/i) {
            mn_lcm = (a+k)*(b+k)/i;
            mn_k = k;
        }
    }

    for (auto i : div) {
        ll k = (x/i)-b%(x/i);
        if (mn_lcm > (a+k)*(b+k)/(x/i)) {
            mn_lcm = (a+k)*(b+k)/(x/i);
            mn_k = k;
        }
    }

    printf("%lld", mn_k);
}