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

ll d, k, a, b, t;

int main () {
    scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);

    if (k >= d) {
        printf("%lld\n", d * a);
        exit(0);
    }
    ll ans = 0;
    ans += k * a;

    // jesli jazda jest tansza od spaceru
    if (t + k*a <= k*b) {
        ll repairs = (d - k) / k;
        ans += repairs * t;
        ans += repairs * k * a;

        // jedziemy albo idziemy ostatni kawalek
        ll remaining_d = d - k - repairs*k;
        ans += min(t + remaining_d*a, remaining_d*b);
    }
    else {
        ans += (d - k) * b;
    }

    printf("%lld\n", ans);

    return 0;
}