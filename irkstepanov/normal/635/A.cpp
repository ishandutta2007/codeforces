#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));

    int k, x;
    cin >> k >> x;
    while (k--) {
        int x, y;
        cin >> x >> y;
        v[x - 1][y - 1] = 1;
    }

    int ans = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = a; b < n; ++b) {
            for (int c = 0; c < m; ++c) {
                for (int d = c; d < m; ++d) {
                    int cnt = 0;
                    for (int i = a; i <= b; ++i) {
                        for (int j = c; j <= d; ++j) {
                            cnt += v[i][j];
                        }
                    }
                    if (cnt >= x) {
                        ++ans;
                    }
                }
            }
        }
    }

    cout << ans << "\n";

}