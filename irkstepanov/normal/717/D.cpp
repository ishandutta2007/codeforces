#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

typedef vector<vector<ld> > matrix;

matrix operator*(const matrix& a, const matrix& b)
{
    int n = sz(a);
    vector<vector<ld> > c(n, vector<ld>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

matrix binpow(matrix a, int n)
{
    int k = sz(a);
    vector<vector<ld> > ans(k, vector<ld>(k));
    for (int i = 0; i < k; ++i) {
        ans[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            ans = ans * a;
        }
        n >>= 1;
        a = a * a;
    }
    return ans;
}

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    int x;
    cin >> x;

    set<int> powers;
    for (int i = 0; i < 20; ++i) {
        powers.insert(1 << i);
    }
    int init_x = x;
    while (!powers.count(x + 1)) {
        ++x;
    }

    vector<ld> prob(x + 1);
    for (int i = 0; i <= init_x; ++i){
        cin >> prob[i];
    }

    vector<vector<ld> > base(x + 1, vector<ld>(x + 1));
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= x; ++j) {
            base[i ^ j][j] = prob[i];
        }
    }

    matrix m = binpow(base, n - 1);
    ld ans = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j <= x; ++j) {
            ans += m[i][j] * prob[j];
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << '\n';

}