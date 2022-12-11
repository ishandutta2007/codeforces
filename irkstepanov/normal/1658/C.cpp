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
        int n;
        cin >> n;
        vector<int> a(n);
        int f = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                f = i;
            }
        }
        if (f == -1) {
            cout << "NO\n";
            continue;
        }
        int pr = 1;
        bool ok = true;
        for (int i = f + 1; i < n; ++i) {
            if (a[i] > pr + 1 || a[i] == 1) {
                ok = false;
            }
            pr = a[i];
        }
        for (int i = 0; i < f; ++i) {
            if (a[i] > pr + 1 || a[i] == 1) {
                ok = false;
            }
            pr = a[i];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

}