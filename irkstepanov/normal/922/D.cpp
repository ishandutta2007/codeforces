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

struct data {
    ll a, b;
    string s;
};

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

    vector<data> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = {0, 0, s};
        for (int j = 0; j < sz(s); ++j) {
            if (s[j] == 's') {
                ++a[i].a;
            } else {
                ++a[i].b;
            }
        }
    }

    sort(all(a), [&] (data& p, data& q) {
        return p.a * q.b > p.b * q.a;
    });

    ll sum = 0;
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = sz(a[i].s) - 1; j >= 0; --j) {
            if (a[i].s[j] == 's') {
                ans += sum;
            } else {
                ++sum;
            }
        }
    }

    cout << ans << "\n";

}