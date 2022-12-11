#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s;
    cin >> s;
    vector<string> v;
    int pos = 0;

    while (pos < sz(s)) {
        string ans = "";
        if (s[pos] == '@') {
            cout << "No solution\n";
            return 0;
        }
        for (; pos < sz(s); ++pos) {
            ans += s[pos];
            if (s[pos] == '@') {
                break;
            }
        }
        if (ans[sz(ans) - 1] != '@') {
            cout << "No solution\n";
            return 0;
        }
        if (pos + 1 == sz(s)) {
            cout << "No solution\n";
            return 0;
        }
        if (s[pos + 1] == '@') {
            cout << "No solution\n";
            return 0;
        }
        ans += s[pos + 1];
        pos += 2;
        int cnt = 0;
        for (int i = pos; i < sz(s); ++i) {
            if (s[i] == '@') {
                ++cnt;
            }
        }
        if (!cnt) {
            for (int i = pos; i < sz(s); ++i) {
                ans += s[i];
            }
            pos = sz(s);
        }
        v.pb(ans);
    }

    for (int i = 0; i < sz(v); ++i) {
        cout << v[i];
        if (i != sz(v) - 1) {
            cout << ",";
        }
    }
    cout << "\n";

}