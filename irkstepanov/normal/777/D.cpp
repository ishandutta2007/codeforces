#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;

struct node
{
    int minn;
    int posMin;
    node() : minn(inf), posMin(-1) {}
    node(int minn, int posMin) : minn(minn), posMin(posMin) {}
};

vector<node> t;

void build(int v, int tl, int tr, vector<int>& a)
{
    if (tl == tr) {
        t[v] = {a[tl], tl};
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].minn = min(t[v * 2].minn, t[v * 2 + 1].minn);
    if (t[v].minn == t[v * 2].minn) {
        t[v].posMin = t[v * 2].posMin;
    } else {
        t[v].posMin = t[v * 2 + 1].posMin;
    }
}

pii get(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return {t[v].minn, t[v].posMin};
    }
    int tm = (tl + tr) >> 1;
    pii ans = {inf, -1};
    if (l <= tm) {
        pii g = get(v * 2, tl, tm, l, min(r, tm));
        if (g.first < ans.first) {
            ans = g;
        }
    }
    if (r > tm) {
        pii g = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        if (g.first < ans.first) {
            ans = g;
        }
    }
    return ans;
}

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");
    //ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        s[i] = t.substr(1, sz(t) - 1);
    }

    vector<vector<int> > dp(n);
    vector<vector<int> > p(n);
    for (int i = 0; i <= sz(s[0]); ++i) {
        dp[0].pb(sz(s[0]) - i);
        p[0].pb(-1);
    }

    t.resize(4 * sz(dp[0]));
    build(1, 0, sz(dp[0]) - 1, dp[0]);

    for (int i = 1; i < n; ++i) {
        int f = -1;
        for (int j = 0; j < sz(s[i]) && j < sz(s[i - 1]); ++j) {
            if (s[i][j] != s[i - 1][j]) {
                f = j;
                break;
            }
        }
        for (int j = 0; j <= sz(s[i]); ++j) {
            int r;
            if (f == -1) {
                r = min(j, sz(s[i - 1]));
            } else {
                if (j <= f) {
                    r = j;
                } else {
                    if (s[i - 1][f] < s[i][f]) {
                        r = sz(s[i - 1]);
                    } else {
                        r = f;
                    }
                }
            }
            pii g = get(1, 0, sz(dp[i - 1]) - 1, 0, r);
            dp[i].pb(g.first + sz(s[i]) - j);
            p[i].pb(g.second);
        }
        t.resize(4 * sz(dp[i]));
        build(1, 0, sz(dp[i]) - 1, dp[i]);
    }

    vector<string> ans(n);
    int curr = t[1].posMin;
    int i = n - 1;
    while (curr != -1) {
        ans[i] = s[i].substr(0, curr);
        curr = p[i][curr];
        --i;
    }

    for (int i = 0; i < n; ++i) {
        cout << "#" << ans[i] << "\n";
    }

}