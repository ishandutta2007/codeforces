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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sigma = 26;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    set<vector<int> > s;

    while (n--) {
        string t;
        cin >> t;
        vector<int> a(sigma);
        for (int i = 0; i < sz(t); ++i) {
            a[t[i] - 'a'] = 1;
        }
        s.insert(a);
    }

    cout << sz(s) << "\n";

}