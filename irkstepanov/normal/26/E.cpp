#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, w;
    cin >> n >> w;

    if (w < 1) {
        cout << "No\n";
        return 0;
    }

    vector<int> a(n);
    int one = -1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 1) {
            one = i;
        }
    }

    if (n == 1) {
        if (w != a[0]) {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        for (int i = 0; i < 2 * a[0]; ++i) {
            cout << "1 ";
        }
        cout << "\n";
        return 0;
    }

    if (w > sum) {
        cout << "No\n";
        return 0;
    }

    if (one != -1) {
        int pos = 0;
        if (pos == one) {
            ++pos;
        }
        cout << "Yes\n";
        for (int i = 0; i < w - 1; ++i) {
            cout << pos + 1 << " " << pos + 1 << " ";
            --a[pos];
            if (a[pos] == 0) {
                ++pos;
            }
            if (pos == one) {
                ++pos;
            }
        }
        cout << one + 1 << " ";
        while (pos < n) {
            cout << pos + 1 << " " << pos + 1 << " ";
            --a[pos];
            if (a[pos] == 0) {
                ++pos;
            }
            if (pos == one) {
                ++pos;
            }
        }
        cout << one + 1 << "\n";
        return 0;
    }

    if (w == 1) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    vector<int> ans;
    vector<char> used;
    ans.pb(2);
    used.pb(true);
    for (int i = 0; i < a[0] - 1; ++i) {
        ans.pb(1);
        ans.pb(1);
        used.pb(false);
        used.pb(false);
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            ans.pb(i + 1);
            ans.pb(i + 1);
            used.pb(false);
            used.pb(false);
        }
    }

    ans.pb(2);
    used.pb(true);
    ans.pb(1);
    used.pb(true);

    for (int i = 1; i < a[1]; ++i) {
        ans.pb(2);
        ans.pb(2);
        used.pb(false);
        used.pb(false);
    }
    ans.pb(1);
    used.pb(true);

    vector<int> tmp;
    for (int i = 0; i < sz(ans); ++i) {
        if (used[i]) {
            cout << ans[i] << " ";
        } else if (w > 2) {
            tmp.pb(ans[i]);
            tmp.pb(ans[i + 1]);
            --w;
            ++i;
        } else {
            cout << ans[i] << " ";
        }
    }
    for (int x : tmp) {
        cout << x << " ";
    }
    cout << "\n";

}