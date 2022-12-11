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

map<char, int> mapa;

bool eq(string a, string b) {
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = char(a[i] - 'A' + 'a');
        }
        if (b[i] >= 'A' && b[i] <= 'Z') {
            b[i] = char(b[i] - 'A' + 'a');
        }
    }

    for (int i = 0; i < sz(a); ++i) {
        if (a[i] == b[i]) {
            continue;
        }
        if (!mapa.count(a[i]) || !mapa.count(b[i])) {
            return false;
        }
        if (mapa[a[i]] != mapa[b[i]]) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    mapa['0'] = 1;
    mapa['o'] = 1;
    mapa['1'] = 2;
    mapa['l'] = 2;
    mapa['i'] = 2;

    string s;
    cin >> s;

    int n;
    cin >> n;

    while (n--) {
        string t;
        cin >> t;
        if (sz(s) != sz(t)) {
            continue;
        }
        if (eq(s, t)) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

}