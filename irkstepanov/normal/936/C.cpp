#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int sigma = 26;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> cnt(sigma, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
        --cnt[t[i] - 'a'];
    }
    for (int i = 0; i < sigma; ++i) {
        if (cnt[i] != 0) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<int> ans;

    int lf, rg;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[0]) {
            lf = rg = i;
        }
    }

    for (int i = 1; i < n; ++i) {
        int pos = -1;
        for (int j = 0; j < n; ++j) {
            if (j >= lf && j <= rg) {
                continue;
            }
            if (s[j] == t[i]) {
                pos = j;
            }
        }
        if (pos == rg + 1) {
            ++rg;
            continue;
        }
        string p = s.substr(lf, rg - lf + 1);
        if (pos > rg) {
            string u = s.substr(0, lf);
            string v = s.substr(rg + 1, pos - rg - 1);
            string w = s.substr(pos + 1, n - pos - 1);
            string y = "";
            y += s[pos];
            ans.pb(sz(w));
            ans.pb(sz(p) + sz(v) + sz(y));
            ans.pb(sz(p) + sz(u) + sz(w));
            reverse(all(u));
            reverse(all(v));
            s = u + w + p + y + v;
            lf = sz(w) + sz(u);
            rg = lf + sz(p);
        } else {
            string w = s.substr(0, pos);
            string u = s.substr(pos + 1, lf - pos - 1);
            string v = s.substr(rg + 1, n - rg - 1);
            string y = "";
            y += s[pos];
            ans.pb(sz(u) + sz(p) + sz(v));
            ans.pb(sz(y));
            ans.pb(sz(p) + sz(u) + sz(w));
            reverse(all(w));
            reverse(all(v));
            s = w + u + p + y + v;
            lf = sz(w) + sz(u);
            rg = lf + sz(p);
        }
    }

    assert(s == t);
    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}