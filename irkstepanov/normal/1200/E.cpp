#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

vector<int> p_func(const string& s) {
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string curr = "";
    while (n--) {
        string s;
        cin >> s;
        string t = s;
        t += "#";
        for (int i = max(0, sz(curr) - sz(s)); i < sz(curr); ++i) {
            t += curr[i];
        }
        vector<int> p = p_func(t);
        int val = p.back();
        for (int i = val; i < sz(s); ++i) {
            curr += s[i];
        }
    }

    cout << curr << "\n";

}