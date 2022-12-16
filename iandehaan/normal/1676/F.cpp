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
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        rep(i, 0, n) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int> a;
        for (pii x : cnt) {
            if (x.second >= k) a.pb(x.first);
        }
        sort(all(a));
        int out = 0;
        int prev = -2;
        int run = 1;
        int out1 = 0;
        int out2 = 0;
        for (int x : a) {
            if (x == prev+1) {
                run++;
                if (run > out) {
                    out = run;
                    out2 = x;
                    out1 = x - run + 1;
                }
            } else {
                run = 1;
                if (run > out) {
                    out = run;
                    out1 = x;
                    out2 = x;
                }
            }
            prev = x;
        }
        if (out == 0) cout <<  -1 << '\n';
        else cout << out1 << ' ' << out2 << '\n';
    }
}