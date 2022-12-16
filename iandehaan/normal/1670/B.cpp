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
        string a;
        cin >> a;
        int lastspec = 0;
        set<char> spec;
        int k;
        cin >> k;
        rep(i, 0, k) {
            char c;
            cin >> c;
            spec.insert(c);
        }

        int out = 0;
        rep(i, 0, n) {
            if (spec.count(a[i]) != 0) {
                out = max(out, i-lastspec);
                lastspec = i;
            }
        }
        cout << out << '\n';
    }
}