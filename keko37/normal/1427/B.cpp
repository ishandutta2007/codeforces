#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, k;
string s;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        v.clear();
        int prosli = -1, br = 0, lose = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                lose++;
                br++;
                if (i != n-1 && s[i + 1] == 'W' && prosli != -1) {
                    v.push_back(i - prosli);
                }
            } else {
                prosli = i;
                br = 0;
            }
        }
        if (lose <= k) {
            cout << 2 * n - 1 << '\n';
        } else if (lose == n) {
            cout << max(0, 2 * k - 1) << '\n';
        } else {
            sort(v.begin(), v.end());
            int res = 2 * (n - lose) - (v.size() + 1) + 2 * k;
            for (auto x : v) {
                if (k >= x) {
                    k -= x;
                    res++;
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}