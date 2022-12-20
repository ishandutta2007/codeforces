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

#define MAXN 200'010

int n;
int a[MAXN];

int memo[MAXN];
vi lookback[MAXN];
bool dp(int x) {
    if (x < -1) return false;
    if (x == -1) return true;
    if (memo[x] != -1) return memo[x];

    // Case 1: our current thing does it
    int prevpos = x-a[x]-1;
    if (dp(prevpos)) return memo[x] = true;

    // Case 2: other thing does it
    for (int prev : lookback[x]) {
        if (dp(prev)) return memo[x] = true;
    }
    return memo[x] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) {
            memo[i] = -1;
            lookback[i].clear();
        }

        rep(i, 0, n) {
            int pos = i + a[i];
            if (pos < n) lookback[pos].pb(i-1);
        }

        if (dp(n-1)) cout << "YES\n";
        else cout << "NO\n";
    }
}