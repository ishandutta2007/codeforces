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

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> total(n + 1), awake(n + 1);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        total[i] = total[i - 1];
        awake[i] = awake[i - 1];
        if (t == 1) {
            awake[i] += a[i];
        }
        total[i] += a[i];
    }

    int ans = 0;

    for (int i = 1; i + k - 1 <= n; ++i) {
        int j = i + k - 1;
        int res = awake[n] + (total[j] - total[i - 1]) - (awake[j] - awake[i - 1]);
        ans = max(ans, res);
    }
    cout << ans << "\n";

}