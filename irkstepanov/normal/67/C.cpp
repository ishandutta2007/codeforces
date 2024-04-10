#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;

const int nmax = 4050;
const int inf = 1e9;
const int sigma = 256;

int dp[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int ins, del, rep, exc;
    string a, b;
    cin >> ins >> del >> rep >> exc >> a >> b;

    for (int i = 0; i < nmax; ++i) {
        for (int j = 0; j < nmax; ++j) {
            dp[i][j] = inf;
        }
    }

    for (int i = 0; i <= sz(a); ++i) {
        dp[i][0] = i * del;
    }

    vector<int> mapb(sigma, -1);


    for (int j = 1; j <= sz(b); ++j) {
        dp[0][j] = j * ins;
        mapb[b[j - 1]] = j - 1;
        vector<int> mapa(sigma, -1);
        for (int i = 1; i <= sz(a); ++i) {
            mapa[a[i - 1]] = i - 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + del);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + ins);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + rep);
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            if (i >= 2 && j >= 2 && a[i - 1] != b[j - 1]) {
                char x = a[i - 1], y = b[j - 1];
                if (mapb[x] == -1 || mapa[y] == -1) {
                    continue;
                }
                int posa = mapa[y], posb = mapb[x];
                dp[i][j] = min(dp[i][j], dp[posa][posb] + exc + (i - 2 - posa) * del + (j - 2 - posb) * ins);
            }
        }
    }

    cout << dp[sz(a)][sz(b)] << "\n";

}