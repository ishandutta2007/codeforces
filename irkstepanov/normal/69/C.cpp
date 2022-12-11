#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

int convert(const string& s) {
    int ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans *= 10;
        ans += (s[i] - '0');
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

    int n, useless, k, q;
    cin >> n >> useless >> k >> q;
    for (int i = 0; i < useless; ++i) {
        string s;
        cin >> s;
    }

    map<string, vector<pair<string, int> > > comp;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        s = s.substr(0, sz(s) - 1);
        comp[s] = {};
        while (true) {
            string t;
            cin >> t;
            string u;
            cin >> u;
            bool cont = false;
            if (u[sz(u) - 1] == ',') {
                cont = true;
                u = u.substr(0, sz(u) - 1);
            }
            comp[s].pb({t, convert(u)});

            if (!cont) {
                break;
            }
        }
    }

    vector<map<string, int> > cnt(n);
    while (q--) {
        int p;
        cin >> p;
        --p;
        string s;
        cin >> s;
        ++cnt[p][s];
        string name = "";
        for (auto it : comp) {
            bool good = true;
            for (int i = 0; i < sz(it.second); ++i) {
                if (!cnt[p].count(it.second[i].first) || cnt[p][it.second[i].first] < it.second[i].second) {
                    good = false;
                    break;
                }
            }
            if (good) {
                name = it.first;
                break;
            }
        }
        if (name == "") {
            continue;
        }
        ++cnt[p][name];
        auto v = comp[name];
        for (int i = 0; i < sz(v); ++i) {
            cnt[p][v[i].first] -= v[i].second;
            if (cnt[p][v[i].first] == 0) {
                cnt[p].erase(v[i].first);
            }
        }
    }

    for (int p = 0; p < n; ++p) {
        int sum = 0;
        for (auto it : cnt[p]) {
            ++sum;
        }
        cout << sum << "\n";
        for (auto it : cnt[p]) {
            cout << it.first << " " << it.second << "\n";
        }
    }

}