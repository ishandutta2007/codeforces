#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define forn(i, n) for (int (i) = 0; (i) < n; ++(i))
#define ford(i, n) for (int (i) = (n) - 1; (i) >= 0; --(i))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

map<string, vector<int> > values;

int conv(const string& s)
{
    int ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans *= 10;
        ans += (s[i] - '0');
    }
    return ans;
}

bool in_range(int val)
{
    return val >= -10000 && val <= 10000;
}

void f(const string& s)
{
    if (sz(s)) {
        if (sz(s) == 1) {
            if (s == "0") {
                values[s] = {0};
            } else {
                values[s] = {-(s[0] - '0'), s[0] - '0'};
            }
        } else {
            vector<int> ans;
            if (s[0] != '0') {
                int val = conv(s);
                if (in_range(val)) {
                    ans.pb(val);
                    ans.pb(-val);
                }
            }
            for (int i = 0; i < sz(s) - 1; ++i) {
                string a = s.substr(0, i + 1);
                string b = s.substr(i + 1, sz(s) - (i + 1));
                for (int x : values[a]) {
                    for (int y : values[b]) {
                        int z = x + y;
                        if (in_range(z)) {
                            ans.pb(z);
                        }
                        z = x - y;
                        if (in_range(z)) {
                            ans.pb(z);
                        }
                        z = x * y;
                        if (in_range(z)) {
                            ans.pb(z);
                        }
                    }
                }
            }
            sort(all(ans));
            ans.resize(unique(all(ans)) - ans.begin());
            values[s] = ans;
        }
    }
    if (sz(s) != 4) {
        string t = s;
        t += "0";
        f(t);
        for (int d = 1; d < 10; ++d) {
            t[sz(t) - 1] = (char)(d + '0');
            f(t);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    f("");

    vector<vector<string> > v(10001);
    for (auto& it : values) {
        if (sz(it.first) != 4) {
            continue;
        }
        for (int x : it.second) {
            if (x >= 0 && x <= 10000) {
                v[x].pb(it.first);
            }
        }
    }

    int k, m;
    cin >> k >> m;
    set<string> ans;

    for (int i = 0; i <= k; ++i) {
        for (string& x : v[i]) {
            for (string& y : v[k - i]) {
                string t = x + y;
                if (!ans.count(t)) {
                    ans.insert(t);
                    --m;
                    if (!m) {
                        for (string z : ans) {
                            cout << z << "\n";
                        }
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NOT Enough\n";

}