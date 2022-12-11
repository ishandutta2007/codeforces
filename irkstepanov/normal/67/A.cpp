#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans(n, -1);
    vector<pii> blocks;

    int lst = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '=') {
            continue;
        } else {
            blocks.pb({lst, i});
            lst = i + 1;
        }
    }
    blocks.pb({lst, n - 1});

    for (int x = 1, put = 0; put < n; ++x) {
        for (pii& p : blocks) {
            int l = p.first, r = p.second;
            if (ans[l] != -1) {
                continue;
            }
            bool good = true;
            if (l > 0 && s[l - 1] == 'R') {
                if (ans[l - 1] == -1 || ans[l - 1] == x) {
                    good = false;
                }
            }
            if (r < n - 1 && s[r] == 'L') {
                if (ans[r + 1] == -1 || ans[r + 1] == x) {
                    good = false;
                }
            }
            if (good) {
                for (int i = l; i <= r; ++i) {
                    ans[i] = x;
                    ++put;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}