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
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

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

    ll u;
    cin >> u;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ptr = 2;
    ld ans = -1;
    for (int i = 0; i + 2 < n; ++i) {
        while (ptr + 1 < n && a[ptr + 1] - a[i] <= u) {
            ++ptr;
        }
        if (a[ptr] - a[i] <= u && ptr >= i + 2) {
            ans = max(ans, ld(a[ptr] - a[i + 1]) / (a[ptr] - a[i]));
        }
    }

    if (ans == -1) {
        cout << "-1\n";
        return 0;
    }

    cout << fixed;
    cout.precision(20);
    cout << ans << "\n";

}