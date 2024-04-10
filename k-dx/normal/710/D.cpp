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
ll a1, b1, a2, b2, l, r;

pair<ll, ll> ext_euc (ll a, ll b) {
    if (b == 0LL) {
        return { 1LL, 0LL };
    }
    auto res = ext_euc(b, a % b);
    // printf("a = %lld, b = %lld ", a, b);
    // printf("x = %lld, y = %lld\n", res.second, res.first - res.second * (a / b));
    return { res.second, res.first - res.second * (a / b) };
}

int main () {
    scanf("%lld %lld %lld %lld %lld %lld", &a1, &b1, &a2, &b2, &l, &r);
    auto res = ext_euc(a1, -a2);
    deb("%lld * %lld + %lld * %lld = %lld = gcd(%lld, %lld)\n",
            a1, res.first,
            -a2, res.second,
            a1*res.first + -a2*res.second,
            a1, -a2);

    ll nwd = a1*res.first + -a2*res.second;
    // if (nwd < 0) nwd = -nwd;
    deb("nwd = %lld\n", nwd);
    ll nww = a1 * (-a2) / nwd;
    deb("nww = %lld\n", nww);
    ll m = (b2 - b1) / nwd;
    deb("m = %lld\n", m);

    if ((b2 - b1) % nwd != 0) {
        printf("0\n");
        exit(0);
    }

    deb("xk = %lld, xl = %lld\n", a1*res.first*m + b1, a2*res.second*m + b2);

    /*
    for (int w = -35; w <= 900; w++) {
        ll newk = (res.first*m + nww/a1 * w);
        ll newl = (res.second*m - nww/-a2 * w);
        printf("w: %2d | ", w);
        printf("%lld %lld -> %lld | ", newk, newl, a1*newk + (-a2)*newl);
        printf("xl = %lld, xk = %lld\n", b2 + a2*newl, b1 + a1*newk);
    }
    */
    
    // jezeli funkcja malejaca
    if (res.first*m + nww/a1 * 0 > res.first*m + nww/a1 * 1) {
        deb("malejaca!\n");

        ll w0k = -res.first*m / (nww / a1);
        w0k += 2;
        while (res.first*m + nww/a1*w0k < 0) w0k--;

        ll w0l = res.second*m / (nww / (-a2));
        w0l += 2;
        while (res.second*m - nww/-a2*w0l < 0) w0l--;

        ll wmax = ((l - b1)/nww - res.first*m/(nww/a1));
        wmax += 2;
        while (a1*(res.first*m + nww/a1 * wmax) + b1 < l) wmax--; 

        ll wmin = ((r - b1)/nww - res.first*m /(nww / a1));
        wmin -= 2;
        while (a1*(res.first*m + nww/a1 * wmin) + b1 > r) wmin++;

        ll mx = min({ w0k, w0l, wmax });

        deb("przy w0k: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*w0k,
                res.second*m - nww/-a2*w0k);

        deb("przy w0l: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*w0l,
                res.second*m - nww/-a2*w0l);

        deb("przy wmax: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*wmax,
                res.second*m - nww/-a2*wmax);
        deb("przy wmin: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*wmin,
                res.second*m - nww/-a2*wmin);

        logg(wmax, wmin);
        logg(wmin, mx);

        if (mx < wmin) printf("0\n");
        else printf("%lld\n", abs(mx - wmin) + 1);
    }
    else {
        deb("rosnaca!\n");

        ll w0k = -res.first*m / (nww / a1);
        w0k -= 2;
        while (res.first*m + nww/a1*w0k < 0) w0k++;

        ll w0l = res.second*m / (nww / (-a2));
        w0l -= 2;
        while (res.second*m - nww/-a2*w0l < 0) w0l++;

        ll wmax = ((r - b1)/nww - res.first*m/(nww/a1));
        wmax += 2;
        while (a1*(res.first*m + nww/a1 * (wmax)) + b1 > r) wmax--; 

        ll wmin = ((l - b1)/nww - res.first*m/(nww/a1));
        wmin -= 2;
        deb("x przy wmin(%lld) = %lld\n", wmin, a1*(res.first*m + nww/a1 * wmin) + b1);
        while (a1*(res.first*m + nww/a1 * wmin) + b1 < l) wmin++;

        ll mi = max({ w0k, w0l, wmin });

        deb("przy w0k: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*w0k,
                res.second*m - nww/-a2*w0k);

        deb("przy w0l: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*w0l,
                res.second*m - nww/-a2*w0l);

        deb("przy wmax: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*wmax,
                res.second*m - nww/-a2*wmax);
        deb("przy wmin: k' = %lld, l' = %lld\n", 
                res.first*m + nww/a1*wmin,
                res.second*m - nww/-a2*wmin);

        logg(wmax, wmin);
        logg(mi, wmax);

        if (wmax < mi) printf("0\n");
        else printf("%lld\n", abs(wmax - mi) + 1);
    }

    /*
    ll wmax = (r - b1 - res.first*m*a1) / nww;
    if (wmax > 0 and a1*(res.first*m + nww/a1 * (wmax+1)) + b1 <= r)
        wmax++;
    else if (wmax < 0 and a1*(res.first*m + nww/a1 * (wmax-1)) + b1 <= r)
        wmax--;

    deb("przy wmax: k' = %lld, l' = %lld\n", 
            res.first*m + nww/a1*wmax,
            res.second*m - nww/-a2*wmax);

    ll wmin = (l - b1 - res.first*m*a1) / nww;
    if (wmin > 0 and a1*(res.first*m + nww/a1 * wmin) + b1 < l)
        wmin++;
    else if (wmin < 0 and a1*(res.first*m + nww/a1 * wmin) + b1 < l)
        wmin--;

    deb("przy wmin: k' = %lld, l' = %lld\n", 
            res.first*m + nww/a1*wmin,
            res.second*m - nww/-a2*wmin);

    // deb("wmax = %lld, wmin = %lld\n", wmax, wmin);
    logg(wmax, wmin);

    if (res.first*m + nww/a1*wmax < 0) {
        printf("0\n");
        exit(0);
    }
    printf("%lld\n", max(0LL, abs(wmax - wmin) + 1));
    */

    return 0;
}