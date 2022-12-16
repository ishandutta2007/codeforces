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
        string a, b;
        cin >> a >> b;
        if (sz(b) == 1 && b[0] == 'a') {
            cout << 1 << endl;
            continue;
        }

        int numa = 0;
        int numb = 0;
        for (char c : a) if (c == 'a') numa++;
        for (char c : b) if (c == 'a') numb++;
        if (numa == 0) {
            cout << 1 << endl;
            continue;
        }

        if (numb > 0) {
            cout << -1 << endl;
            continue;
        }

        // numa > 0, numb == 0
        ll out = 1;
        for (ll i = numa; i >= 1; i--) {
            out *= 2;
        }
        cout << out << endl;
    }
}