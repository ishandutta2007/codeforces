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
        char a[n];
        rep(i, 0, n) cin >> a[i];

        int pref[n];
        pref[0] = 0;
        if (a[0] == '+') pref[0] = 1;
        rep(i, 1, n) {
            pref[i] = pref[i-1];
            if (a[i] == '+') pref[i]++;
        }

        int out = 0;
        rep(i, 0, n) {
            rep(j, i+1, n) {
                // string [i, j]

                int numplus = pref[j];
                if (i != 0) numplus -= pref[i-1];

                int numneg = (j-i+1) - numplus;
                if (numneg >= numplus && (abs(numplus-numneg) % 3 == 0)) {
                    out++;
                }
            }
        }

        cout << out << '\n';
    }
}