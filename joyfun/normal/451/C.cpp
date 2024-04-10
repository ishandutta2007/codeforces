#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll t, n, k, d1, d2;

bool j1(ll n, ll k, ll d1, ll d2) {
    if (d1 + d2 + d2 > k) return false;
    ll sum = d1 + d2 + d2 + n - k;
    if (sum % 3 == 0 && sum / 3 >= d1 + d2) return true;
    return false;
}

bool j2(ll n, ll k, ll d1, ll d2) {
    if (d1 + d1 + d2 > k) return false;
    ll sum = d1 + d1 + d2 + n - k;
    if (sum % 3 == 0 && sum / 3 >= d1 + d2) return true;
    return false;
}

bool j3(ll n, ll k, ll d1, ll d2) {
    if (d1 + d2 > k) return false;
    ll sum = d1 + d2 + n - k;
    ll Max = max(d1, d2);
    if (sum % 3 == 0 && sum / 3 >= Max) return true;
    return false;
}

bool j4(ll n, ll k, ll d1, ll d2) {
    ll Min = min(d1, d2);
    ll Max = max(d1, d2);
    ll sum = 2 * abs(d1 - d2) + Min + n - k;
    if (2 * abs(d1 - d2) + Min > k) return false;
    if (sum % 3 == 0 && sum / 3 >= Max) return true;
    return false;
}

bool judge(ll n, ll k, ll d1, ll d2) {
    if (n % 3) return false;
    if (j1(n, k, d1, d2)) return true;
    if (j2(n, k, d1, d2)) return true;
    if (j3(n, k, d1, d2)) return true;
    if (j4(n, k, d1, d2)) return true;
    return false;
}

int main() {
    scanf("%lld", &t);
    while (t--) {
    scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
    if (judge(n, k, d1, d2)) printf("yes\n");
    else printf("no\n");
    }
    return 0;
}