#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

ll gcd(ll a, ll b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    ll q = gcd(x, y);
    ll p = min((a * q) / x, (b * q) / y);

    cout << (p * x) / q << " " << (p * y) / q << "\n";

}