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
typedef unsigned long long int ull;
typedef long double ld;

const int N = 0;

ll hc, dc;
ll hm, dm;
ll k, w, a;

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%lld %lld", &hc, &dc);
        scanf("%lld %lld", &hm, &dm); 

        scanf("%lld %lld %lld", &k, &w, &a); 

        bool ok = false;
        // g - ile coinow na jedno z ulepszen, k - g na drugie
        for (int i = 0; i <= k; i++) {
            // 10^10 * 2 * 10^5 = 2 * 10^15
            ll r = (hc + a*(k - i)) / dm;
            if (dm * r == hc + a*(k - i)) r--;

            logg(r);

            ull x = (ull)(r+1) * (ull)(dc + w * i);
            if (x / (ull)(dc + w * i) != (ull)(r+1) 
                or x > (ull)(LLONG_MAX)
                or hm - (r+1) * (dc + w * i) <= 0) {
                ok = true;
                break;
            }
        }

        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}