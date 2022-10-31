#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 998244353;
int sum(int a, int b) { return (a + b) % MOD; }

int ways[2][200 * 2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        if (vals[i] != -1)
            vals[i]--;
    }

    if (vals[0] == -1) {
        for (int v = 0; v < 200; v++) {
            ways[0][v] = 1;
        }
    } else {
        ways[0][vals[0]] = 1;
    }

    auto rsum = [&](bool x, int i, int j) {
        if (j < 0) return 0;
        int res = ways[x][j];
        if (i) res = sum(res, MOD - ways[x][i-1]);
        return res;
    };

    for (int i = 1; i < N; i++) {
        bool x = i&1;
        for (int j = 1; j < 200 * 2; j++) {
            ways[!x][j] = sum(ways[!x][j], ways[!x][j-1]);
        }
        memset(ways[x], 0, sizeof(ways[x]));

        for (int pv = 0; pv < 200; pv++) {
            if (vals[i] != -1 && vals[i] != pv)
                continue;

            ways[x][pv] = sum(ways[x][pv], rsum(!x, 0, pv-1));
            ways[x][pv] = sum(ways[x][pv], rsum(!x, 0 + 200, pv-1 + 200));
            ways[x][pv+200] = sum(ways[x][pv+200], rsum(!x, pv, pv));
            ways[x][pv+200] = sum(ways[x][pv+200], rsum(!x, pv+200, pv+200));
            ways[x][pv+200] = sum(ways[x][pv+200], rsum(!x, pv + 1 + 200, 399));
        }

        /*for (int q = 0; q < 400; q++) {
            cout << ways[x][q] << " ";
        }
        cout << endl;*/
    }

    int ans = 0;
    for (int fv = 0; fv < 200; fv++) {
        ans = sum(ans, ways[(N-1)&1][fv+200]);
    }
    cout << ans << endl;

    return 0;
}