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
typedef long double ld;
typedef pair<ld, ld> pld;

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int opta;
    int best = inf;
    for (int a = 1; a <= n; ++a) {
        int x = (n + a - 1) / a;
        if (a + x < best) {
            best = a + x;
            opta = a;
        }
    }

    int ptr = n;
    while (ptr >= 1) {
        int b = max(1, ptr - opta + 1);
        for (int i = b; i <= ptr; ++i) {
            cout << i << " ";
        }
        ptr = b - 1;
    }
    cout << "\n";

}