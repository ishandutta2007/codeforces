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
        if (a == b) {
            cout << "=\n";
            continue;
        }

        char la = a[sz(a)-1];
        char lb = b[sz(b)-1];
        if (la == 'S') la = 'A';
        else if (la == 'M') la = 'B';
        else la = 'C';
        if (lb == 'S') lb = 'A';
        else if (lb == 'M') lb = 'B';
        else lb = 'C';

        bool lessthan = false;
        if (la < lb) lessthan = true;
        if (la == lb) {
            if (la == 'A') {
                if (sz(a) > sz(b)) lessthan = true;
            } else {
                if (sz(a) < sz(b)) lessthan = true;
            }
        }
        if (lessthan) cout << "<\n";
        else cout << ">\n";
    }
}