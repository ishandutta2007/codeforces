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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (sz(s) == 2) {
            cout << s[1] << '\n';
        } else {
            char out = '9';
            for (char c : s) out = min(out, c);
            cout << out << '\n';
        }
    }
}