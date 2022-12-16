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

#define MAXVAL 1010
#define inf 1e9
#define MAXK 1'000'010

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cst[MAXVAL];
    for (int i = 0; i < MAXVAL; i++) cst[i] = inf;
    cst[0] = inf;
    cst[1] = 0;
    
    for (int i = 1; i < MAXVAL; i++) {
        for (int x = 1; x <= i; x++) {
            int newpos = i + i/x;
            if (newpos >= MAXVAL) continue;
            cst[newpos] = min(cst[newpos], cst[i]+1);
        }
    }

    int memo[MAXK];

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int b[n];
        int c[n];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        int maxsz = min(13 * n, k+5);
        for (int i = 0; i <= maxsz; i++) {
            memo[i] = -1;
        }
        memo[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = maxsz; j >= 0; j--) {
                if (memo[j] == -1) continue;
                int newval = j + cst[b[i]];
                if (newval > maxsz) continue;
                if (memo[newval] == -1) memo[newval] = memo[j] + c[i];
                else memo[newval] = max(memo[newval], memo[j] + c[i]);
            }
        }
        int out = 0;
        for (int i = 0; i <= min(maxsz, k); i++) {
            //cout << i << ' ' << memo[i] << endl;
            out = max(out, memo[i]);
        }
        cout << out << endl;
    }
}