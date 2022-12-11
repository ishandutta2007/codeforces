#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                cout << i << "\n";
            }
            continue;
        }
        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int f = 1;
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < k; ++j) {
                cout << f + j * 2 << " ";
            }
            cout << "\n";
            ++f;
            for (int j = 0; j < k; ++j) {
                cout << f + j * 2 << " ";
            }
            cout << "\n";
            f += (k - 1) * 2 + 1;
        }
    }

}