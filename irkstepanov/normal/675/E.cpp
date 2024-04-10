#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const ll inf = 1e18;
const int buben = 150;

vector<int> t;
int n;

int get(int l, int r)
{
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans = max(ans, t[l]);
        }
        if (!(r & 1)) {
            ans = max(ans, t[r]);
        }
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    cin >> n;

    t.resize(2 * n);

    vector<int> a(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        --a[i];
    }
    a[n - 1] = n - 1;

    for (int i = n; i < 2 * n; ++i) {
        t[i] = a[i - n];
    }
    for (int i = n - 1; i; --i) {
        t[i] = max(t[i * 2], t[i * 2 + 1]);
    }

    vector<vector<ll> > dp(n, vector<ll>(buben, inf));
    vector<vector<int> > last(n, vector<int>(buben));

    dp[n - 1][0] = 0;
    for (int j = 0; j < buben; ++j) {
        dp[n - 1][j] = 0;
        last[n - 1][j] = n - 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int len = 1; len < buben && i + len < n; ++len) {
            int r = get(i, i + len);
            dp[i][len] = n - i - 1;
            if (r - i - len < buben) {
                dp[i][len] += dp[i + len][r - i - len];
                last[i][len] = last[i + len][r - i - len];
            } else {
                last[i][len] = i + len;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        int r = a[pos];
        //cout << pos << " " << r << "\n";
        while (pos != n - 1) {
            if (r - pos < buben) {
                ans += dp[pos][r - pos];
                int newr = get(pos, last[pos][r - pos]);
                pos = last[pos][r - pos];
                r = newr;
            } else {
                ans += n - pos - 1;
                int newr = get(pos, r);
                pos = r;
                r = newr;
            }
            //cout << pos << " " << r << "\n";
        }
        //cout << ans << "\n";
        //cout << "\n";
    }

    cout << ans << "\n";

}