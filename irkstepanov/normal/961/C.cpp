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

    int n;
    cin >> n;

    vector<vector<vector<int> > > a(4, vector<vector<int> >(n, vector<int>(n)));

    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                a[k][i][j] = s[j] - '0';
            }
        }
    }

    vector<int> perm = {0, 1, 2, 3};
    int ans = int(1e9);

    do {
        int cnt[2] = {0, 0};
        for (int k = 0; k < 4; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = (i + j) % 2;
                    if (k == 1 || k == 2) {
                        val ^= 1;
                    }
                    for (int z = 0; z < 2; ++z) {
                        if (a[perm[k]][i][j] != (z ^ val)) {
                            ++cnt[z];
                        }
                    }
                }
            }
        }
        ans = min(ans, min(cnt[0], cnt[1]));
    } while (next_permutation(all(perm)));

    cout << ans << "\n";

}