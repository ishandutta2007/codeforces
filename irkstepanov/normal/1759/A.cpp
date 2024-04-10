#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    string yes = "Yes";

    while (tt--) {
        string s;
        cin >> s;
        int pos = -1;
        bool ok = true;
        for (int i = 0; i < sz(s); ++i) {
            char c = s[i];
            if (pos == -1) {
                for (int j = 0; j < sz(yes); ++j) {
                    if (yes[j] == c) {
                        pos = j;
                    }
                }
                if (pos == -1) {
                    ok = false;
                    break;
                }
            } else {
                ++pos;
                if (pos == sz(yes)) {
                    pos = 0;
                }
                if (c != yes[pos]) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

}