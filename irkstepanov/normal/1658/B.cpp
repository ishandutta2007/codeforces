#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int mod = 998244353;
const int nmax = 1500;

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int f[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    f[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        f[i] = f[i - 1];
        mul(f[i], i);
    }

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << "0\n";
            continue;
        }
        int ans = f[n / 2];
        mul(ans, ans);
        cout << ans << "\n";
    }

}