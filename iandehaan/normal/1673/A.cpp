#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (sz(s) % 2 == 0) {
            int out = 0;
            //cout << s << endl;
            for (char c : s) out += c-'a'+1;
            cout << "Alice " << out << endl;
        } else {
            int out = 0;
            int mn = 100;
            for (char c : s) out += c-'a'+1;
            int out1 = out - 2*(s[0]-'a'+1);
            int out2 = out - 2*(s[sz(s)-1]-'a'+1);
            if (sz(s) >= 2) {
                cout << "Alice " << max(out1, out2) << endl;
            } else {
                cout << "Bob " << s[0]-'a'+1 << endl;
            }
        }
    }
}