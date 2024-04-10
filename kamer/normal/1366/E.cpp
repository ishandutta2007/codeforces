#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // do the ranges
    vector<tuple<int, int>> r(m);
    int currIndex = m - 1;
    int currRight = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < b[currIndex]) {
            if (currIndex == 0 || a[i] < b[currIndex - 1]) {
                cout << "0\n";
                return 0;
            }
            if (i == currRight) {
                cout << "0\n";
                return 0;
            }
            r[currIndex] = make_tuple(i + 1, currRight);
            currRight = i;
            currIndex--;
        }
    }
    r[0] = make_tuple(0, currRight);

    // get last b
    vector<int> lastB(m);
    for (int i = 0; i < m; i++) {
        int le = get<0>(r[i]);
        int re = get<1>(r[i]);
        bool found = false;
        for (int j = re; j >= le; j--) {
            if (a[j] == b[i]) {
                found = true;
                lastB[i] = j;
                break;
            }
        }
        if (!found) {
            cout << "0\n";
            return 0;
        }
    }

    // now compute
    ll count = 1;
    for (int i = 0; i < m - 1; i++) {
        count = (count * (ll) (lastB[i + 1] - get<1>(r[i]))) % MOD;
    }

    cout << count << "\n";
}