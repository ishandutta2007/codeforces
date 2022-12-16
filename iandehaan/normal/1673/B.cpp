#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = sz(s);
        set<char> chars;
        for (char c : s) chars.insert(c);
        int m = sz(chars);
        set<char> seen;
        string out = "YES";
        for (int i = 0; i < m; i++) {
            if (seen.count(s[i]) != 0) out = "NO";
            seen.insert(s[i]);
        }

        for (int i = 1; i + m - 1 < n; i++) {
            seen.erase(s[i-1]);
            char c = s[i+m-1];
            if (seen.count(c) != 0) out = "NO";
            seen.insert(c);
        }
        cout << out << endl;
    }
}