// MIPT Shock Content (place 19)

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

const ll inf = 1e18;

vector<int> a;
vector<ll> cnt;
int n, k;
vector<vector<ll> > dp;
ll d = 0;

void dc(int i, int jmin, int jmax, int kmin, int kmax) {
    int j = (jmin + jmax) >> 1;
    for (int t = jmin; t <= j; ++t) {
        d -= cnt[a[t]] * (cnt[a[t]] - 1) / 2;
        ++cnt[a[t]];
        d += cnt[a[t]] * (cnt[a[t]] - 1) / 2;
    }
    dp[i][j] = d + dp[i - 1][kmin];
    int bestK = kmin;
    for (int k = kmin + 1; k < kmax && k < j; ++k) {
        d -= cnt[a[k]] * (cnt[a[k]] - 1) / 2;
        --cnt[a[k]];
        d += cnt[a[k]] * (cnt[a[k]] - 1) / 2;
        if (dp[i][j] > d + dp[i - 1][k]) {
            dp[i][j] = d + dp[i - 1][k];
            bestK = k;
        }
    }
    for (int k = bestK + 1; k < kmax && k < j; ++k) {
        d -= cnt[a[k]] * (cnt[a[k]] - 1) / 2;
        ++cnt[a[k]];
        d += cnt[a[k]] * (cnt[a[k]] - 1) / 2;
    }
    if (j + 1 < jmax) {
        dc(i, j + 1, jmax, bestK, kmax);
    }
    for (int k = bestK; k > kmin; --k) {
        d -= cnt[a[k]] * (cnt[a[k]] - 1) / 2;
        ++cnt[a[k]];
        d += cnt[a[k]] * (cnt[a[k]] - 1) / 2;
    }
    for (int t = j; t >= jmin; --t) {
        d -= cnt[a[t]] * (cnt[a[t]] - 1) / 2;
        --cnt[a[t]];
        d += cnt[a[t]] * (cnt[a[t]] - 1) / 2;
    }
    if (jmin < j) {
        dc(i, jmin, j, kmin, bestK + 1);
    }

}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> k;
    //n = 100000, k = 20;
    a.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        //a[i] = rand() % 100 + 1;
        cin >> a[i];
    }
    dp = vector<vector<ll> >(k + 1, vector<ll>(n + 1, inf));

    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i) {
        //opt.assign(n + 1, -1);
        dc(i, 1, n + 1, 0, n + 1);
        /*int lf = 1, rg = 0;
        ll d = 0;
        while (lf <= n) {
            while (rg + 1 <= n && (opt[rg + 1] == -1 || opt[rg + 1] == lf - 1)) {
                ++rg;
                d -= cnt[a[rg]] * (cnt[a[rg]] - 1) / 2;
                ++cnt[a[rg]];
                d += cnt[a[rg]] * (cnt[a[rg]] - 1) / 2;
                if (opt[rg] == lf - 1) {
                    dp[i][rg] = dp[i - 1][lf - 1] + d;
                }
            }
            d -= cnt[a[lf]] * (cnt[a[lf]] - 1) / 2;
            --cnt[a[lf]];
            d += cnt[a[lf]] * (cnt[a[lf]] - 1) / 2;
            ++lf;
        }*/
        /*for (int j = 1; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";*/
        //cout << "!" << dp[i][1] << "\n";
        //cout << i << " DONE" << endl;
    }

    cout << dp[k][n] << "\n";

}