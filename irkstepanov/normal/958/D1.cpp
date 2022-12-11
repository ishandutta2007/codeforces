#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct Fraction {
    ll num, den;
    Fraction() : num(0), den(1) {}
    Fraction(ll a, ll b) {
        ll g = __gcd(a, b);
        num = a / g;
        den = b / g;
    }
    bool operator<(const Fraction& other) const {
        return num * other.den < other.num * den;
    }
    bool operator==(const Fraction& other) const {
        return num * other.den == den * other.num;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<Fraction, int> mapa;
    vector<Fraction> f(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ll a = 0;
        int pos = 1;
        while (isdigit(s[pos])) {
            a *= 10;
            a += (s[pos] - '0');
            ++pos;
        }
        ++pos;
        ll b = 0;
        while (isdigit(s[pos])) {
            b *= 10;
            b += (s[pos] - '0');
            ++pos;
        }
        pos += 2;
        ll c = 0;
        while (isdigit(s[pos])) {
            c *= 10;
            c += (s[pos] - '0');
            ++pos;
        }
        f[i] = Fraction(a + b, c);
        ++mapa[f[i]];
    }
    for (int i = 0; i < n; ++i) {
        cout << mapa[f[i]] << " ";
    }

}