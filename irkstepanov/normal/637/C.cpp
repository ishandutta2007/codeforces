#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<string> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    int ans = 6;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if (m[i][k] != m[j][k]) {
                    ++cnt;
                }
            }
            ans = min(ans, (cnt - 1) / 2);
        }
    }

    cout << ans << "\n";

}