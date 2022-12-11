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
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    //q = 100500;
    cin >> q;

    while (q--) {
        ll p, q, b;
        cin >> p >> q >> b;
        ll g = __gcd(p, q);
        q /= g;
        g = __gcd(b, q);
        while (g != 1) {
            q /= g;
            g = __gcd(q, g);
        }
        if (q == 1) {
            cout << "Finite\n";
        } else {
            cout << "Infinite\n";
        }
    }

}