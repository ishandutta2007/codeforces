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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    while (q--) {
        int x;
        cin >> x;
        ++c[x - 1];
    }

    int ans = c[0];
    for (int i = 1; i < n; ++i) {
        ans = min(ans, c[i]);
    }
    cout << ans << "\n";

}