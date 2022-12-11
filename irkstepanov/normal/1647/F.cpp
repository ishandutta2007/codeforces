#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9 + 100;

int n;

int solve(vector<int> a) {
    vector<int> lf(n);
    lf[0] = -inf;
    for (int i = 1; i < n; ++i) {
        lf[i] = inf;
        if (a[i - 1] < a[i]) {
            lf[i] = min(lf[i], lf[i - 1]);
        }
        if (lf[i - 1] < a[i]) {
            lf[i] = min(lf[i], a[i - 1]);
        }
    }

    vector<int> rg(n);
    rg[n - 1] = -inf;
    for (int i = n - 2; i >= 0; --i) {
        rg[i] = inf;
        if (a[i + 1] < a[i]) {
            rg[i] = min(rg[i], rg[i + 1]);
        }
        if (rg[i + 1] < a[i]) {
            rg[i] = min(rg[i], a[i + 1]);
        }
    }

    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[pos]) {
            pos = i;
        }
    }

    int dp0 = lf[pos];
    int dp1 = -inf;
    int ans = 0;
    for (int i = pos + 1; i < n; ++i) {
        //cout << "!" << i << " " << dp0 << " " << dp1 << endl;
        if ((dp0 < a[i] && a[i - 1] > rg[i]) || (a[i - 1] < a[i] && dp1 > rg[i])) {
            ++ans;
        }
        int nx0 = inf, nx1 = -inf;
        if (a[i - 1] > a[i]) {
            nx0 = min(nx0, dp0);
        }
        if (dp1 > a[i]) {
            nx0 = min(nx0, a[i - 1]);
        }

        if (dp0 < a[i]) {
            nx1 = max(nx1, a[i - 1]);
        }
        if (a[i - 1] < a[i]) {
            nx1 = max(nx1, dp1);
        }

        dp0 = nx0;
        dp1 = nx1;
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

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = solve(a);
    reverse(all(a));
    //solve(a);
    ans += solve(a);

    cout << ans << "\n";

}