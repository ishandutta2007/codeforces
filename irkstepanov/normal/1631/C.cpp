#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        if (k != n - 1) {
            cout << k << " " << n - 1 << "\n";
            for (int i = 0; i < n; ++i) {
                int j = n - i - 1;
                if (i > j || i == k || j == k || i == n - 1 || j == n - 1) {
                    continue;
                }
                cout << i << " " << j << "\n";
            }
            if (k != 0) cout << 0 << " " << n - 1 - k << "\n";
        } else {
            if (n == 4) {
                cout << "-1\n";
                continue;
            }
            cout << n - 2 << " " << n - 1 << "\n";
            cout << "1 3\n";
            for (int i = 0; i < n; ++i) {
                int j = n - i - 1;
                if (i > j || i == 1 || j == 1 || i == 3 || j == 3 || i == n - 2 || j == n - 2 || i == n - 1 || j == n - 1) {
                    continue;
                }
                cout << i << " " << j << "\n";
            }
            cout << 0 << " " << n - 4 << "\n";
        }
    }

}