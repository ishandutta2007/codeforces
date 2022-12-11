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
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    string s;
    cin >> s;

    vector<int> rg(n);
    rg[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '0') {
            rg[i] = i;
        } else {
            rg[i] = rg[i + 1];
        }
    }

    vector<int> lf(n);
    lf[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == '0') {
            lf[i] = i;
        } else {
            lf[i] = lf[i - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (lf[i] <= p[i] && p[i] <= rg[i]) {
            continue;
        }
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

}