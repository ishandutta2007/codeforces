#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <random>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

ll f(ll n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    ll deg = 2;
    ll ans = 1;
    while (deg * 2 <= n) {
        ans = ans * 2 + deg;
        deg *= 2;
    }
    if (deg == n) {
        return ans;
    }
    return ans + deg + f(n - deg);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;

    cout << f(n) << endl;

}