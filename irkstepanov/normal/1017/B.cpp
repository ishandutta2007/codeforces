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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    ll c[2][2];
    for (int i = 0; i < 2; ++i) {
        c[i][0] = c[i][1] = 0;
    }

    for (int i = 0; i < n; ++i) {
        ++c[a[i] - '0'][b[i] - '0'];
    }

    ll ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    int p1 = (i | j), q1 = (x | y);
                    int p2 = (x | j), q2 = (i | y);
                    if (p1 != p2 || q1 != q2) {
                        //cout << i << " " << j << " " << x << " " << y << endl;
                        ans += c[i][j] * c[x][y];
                    }
                }
            }
        }
    }

    cout << ans / 2 << "\n";

}