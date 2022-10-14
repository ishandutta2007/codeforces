#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 0;

pair<ll,ll> ext_euc (ll a, ll b) {
    if (b == 0LL) return { 1LL, 0LL };
    auto res = ext_euc(b, a % b);
    return { res.second, res.first - res.second * (a / b) };
}

int main () {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    auto res = ext_euc(abs(a), abs(b));
    // printf("%lld %lld\n", res.first, res.second);

    ll nwd = gcd(a, b);

    ll za = -1, zb = -1;
    if (a < 0) za = 1;
    if (b < 0) zb = 1;

    if (abs(c) % nwd == 0LL) printf("%lld %lld\n", za*res.first*c/nwd, zb*res.second*c/nwd);
    else printf("-1\n");

    // int x, y;
    // gcd(a, b, x, y);
    // printf("%d %d", x, y);

    return 0;
}