#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

vector<int> to_seven(int n)
{
    if (n == 0) {
        return {0};
    }
    vector<int> ans;
    while (n) {
        ans.pb(n % 7);
        n /= 7;
    }
    return ans;
}

void fill_zeros(vector<int>& v, int s)
{
    while (sz(v) < s) {
        v.pb(0);
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    //freopen("input", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<int> xx, yy;
    xx = to_seven(n - 1);
    yy = to_seven(m - 1);
    int x = sz(xx), y = sz(yy);

    map<int, int> w;
    for (int i = 0; i < m; ++i) {
        vector<int> v = to_seven(i);
        fill_zeros(v, y);
        if (sz(v) > 7) {
            break;
        }
        int mask = 0;
        for (int d : v) {
            if (mask & (1 << d)) {
                mask = -1;
                break;
            } else {
                mask |= (1 << d);
            }
        }
        if (mask != -1) {
            ++w[mask];
        }
    }

    map<int, int> r;
    for (auto& it : w) {
        for (int mask = 0; mask < (1 << 7); ++mask) {
            if ((it.first & mask) == it.first) {
                r[mask] += it.second;
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> v = to_seven(i);
        fill_zeros(v, x);
        if (sz(v) > 7) {
            break;
        }
        int mask = 0;
        for (int d : v) {
            if (mask & (1 << d)) {
                mask = -1;
                break;
            } else {
                mask |= (1 << d);
            }
        }
        if (mask != -1) {
            mask ^= ((1 << 7) - 1);
            ans += r[mask];
        }
    }

    cout << ans << "\n";

}