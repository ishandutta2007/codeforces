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

// If I color a point something non-unique, then...
// I am forced to color everything exactly that distance from it the same color
// furthermore:: It must form a "clique" of things at that distance

#define MAXN 110

pii a[MAXN];

int getDist(int i, int j) {
    return abs(a[i].first-a[j].first) + abs(a[i].second-a[j].second);
}

vector<int> sizes;
constexpr ll mod = 998244353;
ll memo[110][110];
ll dp(int ind, ll colorsrem) {
    if (ind == sz(sizes)) return 1;
    if (colorsrem <= 0) return 0;

    if (memo[ind][colorsrem] != -1) return memo[ind][colorsrem];

    if (sizes[ind] == 1) {
        return memo[ind][colorsrem] = (colorsrem*dp(ind+1, colorsrem-1)) % mod;
    }
    if (sizes[ind] == 2) {
        return memo[ind][colorsrem] = 
            ((colorsrem * (colorsrem-1) * dp(ind+1, colorsrem-2))
            +
            (colorsrem * dp(ind+1, colorsrem-1)))
            % mod;
    }
    if (sizes[ind] == 3) {
        return memo[ind][colorsrem] = 
            ((colorsrem * (colorsrem-1) * (colorsrem-2) * dp(ind+1, colorsrem-3))
            +
            (colorsrem * dp(ind+1, colorsrem-1)))
            % mod;
    }
    if (sizes[ind] == 4) {
        return memo[ind][colorsrem] = 
            ((colorsrem * (colorsrem-1) * (colorsrem-2) * (colorsrem-3) * dp(ind+1, colorsrem-4))
            +
            (colorsrem * dp(ind+1, colorsrem-1)))
            % mod;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    rep(i, 0, n) cin >> a[i].first >> a[i].second;

    int mindist[n];
    int nummdist[n];
    rep(i, 0, n) {
        mindist[i] = 1e9;
        rep(j, 0, n) {
            if (j == i) continue;
            if (getDist(i, j) < mindist[i]) {
                mindist[i] = getDist(i, j);
                nummdist[i] = 1;
            } else if (getDist(i, j) == mindist[i]) {
                nummdist[i]++;
            }
            //mindist[i] = min(mindist[i], getDist(i, j));
        }
    }

    int cliquesize[n];
    rep(i, 0, n) cliquesize[i] = 1;

    rep(i, 0, n) rep(j, i+1, n) rep(k, j+1, n) rep(x, k+1, n) {
        int ndist = mindist[i];
        if (mindist[j] != ndist || mindist[k] != ndist || mindist[x] != ndist || getDist(i, j) != ndist || getDist(i, k) != ndist || getDist(j, k) != ndist || getDist(i, x) != ndist || getDist(j, x) != ndist || getDist(k, x) != ndist || nummdist[i] != 3 || nummdist[j] != 3 || nummdist[k] != 3 || nummdist[x] != 3) continue;

        cliquesize[i] = 4;
        cliquesize[j] = 4;
        cliquesize[k] = 4;
        cliquesize[x] = 4;
    }

    rep(i, 0, n) rep(j, i+1, n) rep(k, j+1, n) {
        int ndist = mindist[i];
        if (mindist[j] != ndist || mindist[k] != ndist || getDist(i, j) != ndist || getDist(i, k) != ndist || getDist(j, k) != ndist || nummdist[i] != 2 || nummdist[j] != 2 || nummdist[k] != 2) continue;

        cliquesize[i] = 3;
        cliquesize[j] = 3;
        cliquesize[k] = 3;
    }

    rep(i, 0, n) rep(j, i+1, n) {
        int ndist = mindist[i];
        if (cliquesize[i] == 3 || cliquesize[j] == 3 || mindist[j] != ndist || getDist(i, j) != ndist || nummdist[i] != 1 || nummdist[j] != 1) {
            continue;
        }

        cliquesize[i] = 2;
        cliquesize[j] = 2;
    }

    int num4clique = 0;
    int num3clique = 0;
    int num2clique = 0;
    int num1clique = 0;
    rep(i, 0, n) {
        if (cliquesize[i] == 4) num4clique++;
        if (cliquesize[i] == 3) num3clique++;
        if (cliquesize[i] == 2) num2clique++;
        if (cliquesize[i] == 1) num1clique++;
    }

    num4clique /= 4;
    num3clique /= 3;
    num2clique /= 2;

    rep(i, 0, num4clique) sizes.pb(4);
    rep(i, 0, num3clique) sizes.pb(3);
    rep(i, 0, num2clique) sizes.pb(2);
    rep(i, 0, num1clique) sizes.pb(1);

    memset(memo, -1, sizeof memo);
    cout << dp(0, n) << endl;
}