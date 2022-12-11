#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct data
{
    int cost;
    int val;
    bool operator<(const data& other) const
    {
        return cost < other.cost;
    }
};

int solve(const vector<data>& d, int c)
{
    if (d.empty()) {
        return 0;
    }
    int n = sz(d);
    vector<int> pref(n);
    pref[0] = d[0].val;
    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i - 1], d[i].val);
    }
    int ptr = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (ptr + 1 < i && d[ptr + 1].cost + d[i].cost <= c) {
            ++ptr;
        }
        while (ptr >= 0 && d[ptr].cost + d[i].cost > c) {
            --ptr;
        }
        if (ptr >= 0) {
            ans = max(ans, d[i].val + pref[ptr]);
        }
    }
    return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int c, d;
    cin >> c >> d;

    vector<data> x, y;
    while (n--) {
        int val;
        int cost;
        cin >> val >> cost;
        char type;
        cin >> type;
        if (type == 'C') {
            x.pb({cost, val});
        } else {
            y.pb({cost, val});
        }
    }

    sort(all(x));
    sort(all(y));
    int ans = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < sz(x); ++i) {
        if (x[i].cost <= c) {
            ans1 = max(ans1, x[i].val);
        }
    }
    for (int i = 0; i < sz(y); ++i) {
        if (y[i].cost <= d) {
            ans2 = max(ans2, y[i].val);
        }
    }

    if (ans1 && ans2) {
        ans = max(ans, ans1 + ans2);
    }

    ans = max(ans, solve(x, c));
    ans = max(ans, solve(y, d));

    cout << ans << "\n";

}