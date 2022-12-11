#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a), b = abs(b);
    if (a < b) swap(a, b);
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

void wide_gcd(ll a, ll b, ll &x, ll &y)
{
    if (!a)
    {
        x = 0, y = 1;
        return;
    }
    ll x1, y1;
    wide_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
}

int main()
{

    ll A, B, C;
    cin >> A >> B >> C;

    if (!B)
    {
        if (C % A) cout << "-1\n";
        else cout << -C / A << " " << 0 << "\n";
        return 0;
    }

    if (!A)
    {
        if (C % B) cout << "-1\n";
        else cout << 0 << " " << -C / B << "\n";
        return 0;
    }

    ll D = gcd(A, B);
    if (C % D) {cout << "-1\n"; return 0;}

    C /= D;

    ll x0, y0;
    ll a = abs(A), b = abs(B);
    wide_gcd(a, b, x0, y0);

    if (a != A) x0 = -x0;
    if (b != B) y0 = -y0;

    cout << -x0 * C << " " << -y0 * C << "\n";

}