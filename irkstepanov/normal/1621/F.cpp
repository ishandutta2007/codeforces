#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

ll solve(ll a, ll b, ll c, string s) {
    vector<pii> blocks;
    for (int i = 0; i < sz(s); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            blocks.pb({s[i] - '0', 1});
        } else {
            ++blocks.back().second;
        }
    }
    multiset<int> good, bad;
    int cnt = 0;
    for (int i = 0; i < sz(blocks); ++i) {
        if (blocks[i].first == 1) {
            cnt += blocks[i].second - 1;
        } else {
            if (i == 0 || i == sz(blocks) - 1) {
                bad.insert(blocks[i].second);
            } else {
                good.insert(blocks[i].second);
            }
        }
    }
    ll curr = 0;
    ll ans = 0;
    while (true) {
        if (good.empty() && bad.empty()) {
            break;
        }
        if (!good.empty() && *(--good.end()) >= 2) {
            ans = max(ans, curr + a);
        }
        if (!bad.empty() && *(--bad.end()) >= 2) {
            ans = max(ans, curr + a);
        }
        if (cnt >= 1) {
            if (!good.empty() && *(--good.end()) >= 2) {
                auto it = good.lower_bound(2);
                int x = *it;
                good.erase(it);
                good.insert(x - 1);
                curr += a + b;
                ans = max(ans, curr);
                --cnt;
            } else if (!bad.empty() && *(--bad.end()) >= 2) {
                auto it = bad.lower_bound(2);
                int x = *it;
                bad.erase(it);
                bad.insert(x - 1);
                curr += a + b;
                ans = max(ans, curr);
                --cnt;
            } else {
                if (!good.empty()) {
                    good.erase(good.begin());
                    ++cnt;
                    curr += b - c;
                    ans = max(ans, curr);
                    --cnt;
                } else {
                    bad.erase(bad.begin());
                    curr += b - c;
                    ans = max(ans, curr);
                    --cnt;
                }
            }
        } else if (!good.empty() && *good.begin() == 1) {
            good.erase(good.begin());
            ++cnt;
            curr += b - c;
            ans = max(ans, curr);
            --cnt;
        } else {
            break;
        }
    }
    return ans;
}

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
        int n;
        ll a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        ll ans = solve(a, b, c, s);
        int pos = -1;
        for (int i = 1; i < sz(s); ++i) {
            if (s[i] == '1' && s[i - 1] == '1') {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            string t = "";
            for (int i = 0; i < pos; ++i) {
                t += s[i];
            }
            for (int i = pos + 1; i < sz(s); ++i) {
                t += s[i];
            }
            ans = max(ans, solve(a, b, c, t) + b);
        }
        cout << ans << "\n";
    }

}