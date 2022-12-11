#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    int n;
    cin >> n;

    vector<vector<int> > a(n, vector<int>(n));
    bool ok = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                continue;
            }
            bool done = false;
            for (int s = 0; s < n; ++s) {
                for (int t = 0; t < n; ++t) {
                    if (a[i][s] + a[t][j] == a[i][j]) {
                        done = true;
                    }
                }
            }
            if (!done) {
                ok = false;
            }
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

}