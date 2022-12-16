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

constexpr ll inf = 1e7;

#define MAXN 260
int memo[MAXN+1][MAXN+1][2*MAXN+1];
int n, m;
int a[MAXN];

int dp(int x, int alpha, int amt) {
    //cout << x << ' ' << alpha << ' ' << amt << endl;
    if (alpha > MAXN || alpha < 0 || amt > MAXN || amt < -1*MAXN) return inf;
    if (x == 0) {
        if (a[x] + amt >= alpha) return 0;
        else return inf;
    }
    if (memo[x][alpha][amt+MAXN] != -1) return memo[x][alpha][amt+MAXN];
    int myamt = a[x] + amt;

    int out = dp(x, alpha+1, amt);
    out = min(out, dp(x-1, alpha, myamt-alpha)+abs(alpha-myamt));

    /*for (int prevalph = alpha; prevalph < MAXN; prevalph++) {
        // need previous to be at least prevalph
        int medamt = prevalph-myamt;
        // need to transfer in medamt

        out = min(out, dp(x-1, prevalph, medamt)+abs(medamt));
        
    }*/
    return memo[x][alpha][amt+MAXN] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << dp(n-1, 0, 0) << endl;
}