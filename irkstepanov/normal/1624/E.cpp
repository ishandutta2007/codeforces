#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct datum {
    int l, r, i;
    datum() : l(-1), r(-1), i(-1) {}
    datum(int l, int r, int i) : l(l), r(r), i(i) {}
};

int hf(string s) {
    int ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans *= 11;
        ans += (s[i] - '0' + 1);
    }
    return ans;
}

const int nmax = 1400;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<datum> vct(nmax);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j + 1 < sz(s); ++j) {
                string t = s.substr(j, 2);
                int h = hf(t);
                if (vct[h].l == -1) {
                    vct[h] = datum(j, j + 1, i);
                }
            }
            for (int j = 0; j + 2 < sz(s); ++j) {
                string t = s.substr(j, 3);
                int h = hf(t);
                if (vct[h].l == -1) {
                    vct[h] = datum(j, j + 2, i);
                }
            }
        }
        string s;
        cin >> s;
        vector<int> dp(sz(s), -1);
        for (int i = 1; i < sz(s); ++i) {
            string t = s.substr(i - 1, 2);
            int h = hf(t);
            if (vct[h].l != -1) {
                if (i == 1 || dp[i - 2] != -1) {
                    dp[i] = 2;
                }
            }

            if (i == 1) {
                continue;
            }
            t = s.substr(i - 2, 3);
            h = hf(t);
            if (vct[h].l != -1) {
                if (i == 2 || dp[i - 3] != -1) {
                    dp[i] = 3;
                }
            }
        }
        if (dp[sz(s) - 1] == -1) {
            cout << "-1\n";
            continue;
        }
        vector<datum> ans;
        int curr = sz(s) - 1;
        while (curr >= 0) {
            int len = dp[curr];
            string t = s.substr(curr - len + 1, len);
            int h = hf(t);
            ans.pb(vct[h]);
            curr -= len;
        }
        reverse(all(ans));
        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i].l + 1 << " " << ans[i].r + 1 << " " << ans[i].i + 1 << "\n";
        }
    }

}