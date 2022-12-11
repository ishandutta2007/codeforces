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

    int n;
    cin >> n;

    ll w;
    cin >> w;

    ll lf = 0, rg = w;
    ll sum = 0;

    while (n--) {
        ll a;
        cin >> a;
        sum += a;
        lf = max(lf, -sum);
        rg = min(rg, w - sum);
    }

    if (lf <= rg) {
        cout << rg - lf + 1 << "\n";
    } else {
        cout << "0\n";
    }

}