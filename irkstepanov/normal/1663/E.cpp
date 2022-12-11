#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s = "theseus";

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 6 < n; ++j) {
            bool is = true;
            for (int k = 0; k <= 6; ++k) {
                if (a[i][j + k] != s[k]) {
                    is = false;
                }
            }
            if (is) {
                ok = true;
            }
        }
    }
    for (int i = 0; i + 6 < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool is = true;
            for (int k = 0; k <= 6; ++k) {
                if (a[i + k][j] != s[k]) {
                    is = false;
                }
            }
            if (is) {
                ok = true;
            }
        }
    }
    for (int i = 0; i + 6 < n; ++i) {
        for (int j = 0; j + 6 < n; ++j) {
            bool is = true;
            for (int k = 0; k <= 6; ++k) {
                if (a[i + k][j + k] != s[k]) {
                    is = false;
                }
            }
            if (is) {
                ok = true;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";

}