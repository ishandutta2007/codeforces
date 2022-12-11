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
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] == '1') {
            ++cnt;
        }
    }

    int z = 0;
    for (int i = 0; i < sz(b); ++i) {
        if (b[i] == '1') {
            ++z;
        }
    }

    if (z <= cnt) {
        cout << "YES\n";
        return 0;
    }

    if (cnt % 2 == 1 && z <= cnt + 1) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";

}