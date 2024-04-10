#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll& x, ll& y)
{
    if (a < b) {
        return gcd(b, a, y, x);
    }
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll k = a / b, l = a % b;
    ll g = gcd(l, b, x, y);
    y -= k * x;
    return g;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll a1, b1, a2, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;

    ll maxb = max(b1, b2);
    b1 -= maxb, b2 -= maxb;
    l -= maxb, r -= maxb;

    if (b2 == 0) {
        swap(a1, a2);
        swap(b1, b2);
    }

    if (b2 >= 0) {
        b2 %= a2;
    } else {
        b2 = -((-b2) % a2);
        if (b2) {
            b2 += a2;
        }
    }

    //cout << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";

    ll x, y;
    ll g = gcd(a1, a2, x, y);
    //cout << x << " " << y << "\n";
    if (b2 % g) {
        cout << "0\n";
        return 0;
    }

    x *= (b2 / g), y *= (b2 / g);
    ll val = a2 / g;
    if (x >= 0) {
        x %= val;
    } else {
        x = -((-x) % val);
        if (x) {
            x += val;
        }
    }
    ll s1, s2;

    if (a1 * x >= l) {
        s1 = 0;
    } else {
        ll p = (l - a1 * x);
        ll q = a1 * val;
        if (p % q) {
            s1 = p / q + 1;
        } else {
            s1 = p / q;
        }
    }

    if (a1 * x > r) {
        s2 = -1;
    } else {
        s2 = (r - a1 * x) / a1 / val;
    }

    //cout << s1 << " " << s2 << "\n";

    if (s1 <= s2) {
        cout << s2 - s1 + 1 << "\n";
    } else {
        cout << "0\n";
    }

}