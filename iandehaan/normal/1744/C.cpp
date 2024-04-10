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
        int n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        reverse(all(s));
        s += s;

        int prevgreen = -1;
        int out = 0;
        rep(i, 0, sz(s)) {
            if (s[i] == 'g') {
                prevgreen = i;
            }
            if (prevgreen == -1) continue;

            if (s[i] == c) {
                //cout << i << ' ' << prevgreen << endl;
                out = max(out, i-prevgreen);
            }
        }
        cout << out << '\n';
    }
}