#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int nmax = 1e6 + 100;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    vector<bool> is(nmax, false);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        is[x] = true;
    }

    for (int x = 1; x < nmax; ++x) {
        int g = 0;
        for (int y = x; y < nmax; y += x) {
            if (is[y]) {
                g = __gcd(g, y);
            }
        }
        if (g == x) {
            is[x] = true;
        }
    }

    int ans = 0;
    for (int x = 1; x < nmax; ++x) {
        if (is[x]) {
            ++ans;
        }
    }
    cout << ans - n << "\n";

}