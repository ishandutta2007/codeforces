#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll gcd_ex(ll a, ll b, ll& s, ll& t) {
    ll r0 = a, r1 = b, q;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;

    while (r1) {
        q = r0 / r1;

        r0 -= q*r1;
        swap(r0, r1);

        s0 -= q*s1;
        swap(s0, s1);

        t0 -= q*t1;
        swap(t0, t1);
    }

    s = s0;
    t = t0;
    return r0;
}

ll mod_inverse(ll a, ll m) {
    ll s, t;

    a %= m;

    if (a < 0) a += m;

    if (gcd_ex(a, m, s, t) > 1) return -1;

    s %= m;

    if (s <0) s += m;
    return s;
}

ll fast_exp(ll b, ll n, ll m) {
    ll res = 1;
    ll x = b;
    while (n > 0) {
        if (n & 0x01) {
            n--;
            res = (res*x)%m;
        } else {
            n >>= 1;
            x = (x*x) % m;
        }
    }
    return res;
}

ll smodd(ll l, ll r, ll n, ll m) {
    if (n == 1) {
        if ((r-l+1) % 2 == 0) return (r-l+1)/2;
        else if (l % 2 == 1) return (r-l+1)/2 + 1;
        else return (r-l+1)/2;
    } else {
        if ((r-l+1) % 2 == 0) {
            return fast_exp(r-l+1, n-1, m)*((r-l+1)/2);
        }
        else {
            ll out = smodd(l, r, n-1, m);
            ll out2 = fast_exp(r-l+1, n-1, m)-out;
            out2 %= m;
            out2 += m;
            out2 %= m;
            if (l % 2 == 1) swap(out, out2);
            return (out*((r-l+3)/2))%m + (out2*((r-l+1)/2))%m;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll mod = (ll) 998244353;
    ll n, m, l, r;
    cin >> n >> m >> l >> r;


    ll total = fast_exp(r-l + 1, n*m, mod);
   // cout << "total: " << total << endl;
    if ((n*m) % 2 == 0) {
        if ((r-l+1)%2 == 0) {
            
            // just half
            ll out = total*mod_inverse(2, mod);
            out %= mod;
            out += mod;
            out %= mod;
            cout << out << endl;
        } else {
            ll out = (total+1)*mod_inverse(2, mod);
            out %= mod;
            out += mod;
            out %= mod;
            cout << out << endl;
        }
    } else {
        cout << total << endl;
    }

}