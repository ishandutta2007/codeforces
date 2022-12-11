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
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmax = 1e6 + 100;

vector<int> v[nmax];
int pref[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 2; i < nmax; ++i) {
        if (v[i].empty()) {
            for (int j = i; j < nmax; j += i) {
                v[j].pb(i);
            }
        }
    }

    int x;
    cin >> x;
    for (int q : v[x]) {
        int lf = max(q + 1, x - q + 1);
        int rg = x;
        ++pref[lf];
        --pref[rg + 1];
    }

    for (int i = 1; i < nmax; ++i) {
        pref[i] += pref[i - 1];
    }

    int ans = nmax;

    for (int i = 1; i < nmax; ++i) {
        if (pref[i]) {
            for (int p : v[i]) {
                int lf = max(p + 1, i - p + 1);
                int rg = i;
                if (lf <= rg) {
                    ans = min(ans, lf);
                }
            }
        }
    }

    cout << ans << "\n";

}