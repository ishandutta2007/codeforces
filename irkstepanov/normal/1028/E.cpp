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

    bool zeros = true;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i]) {
            zeros = false;
        }
    }

    if (zeros) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << "1 ";
        }
        cout << "\n";
        return 0;
    }

    bool eq = true;
    for (int i = 1; i < n; ++i) {
        if (b[i] != b[i - 1]) {
            eq = false;
        }
    }
    if (eq) {
        cout << "NO\n";
        return 0;
    }

    int val = -1, pos;
    for (int i = 0; i < n; ++i) {
        if (val < b[i]) {
            val = b[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == val && b[(i - 1 + n) % n] != val) {
            pos = i;
        }
    }

    vector<ll> a(n);
    a[pos] = b[pos];
    ll sum = b[pos];
    int i = (pos - 1 + n) % n;
    bool f = true;

    while (i != pos) {
        if (b[i] == 0 && f) {
            sum *= 2;
            f = false;
        }
        sum += b[i];
        a[i] = sum;
        i = (i - 1 + n) % n;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

}