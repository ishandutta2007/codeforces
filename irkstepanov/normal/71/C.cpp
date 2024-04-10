#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool ans = false;

    for (int d = 3; d <= n; ++d) {
        if (n % d) {
            continue;
        }
        for (int i = 0; i < n / d; ++i) {
            bool ok = true;
            for (int j = i; j < n; j += n / d) {
                if (a[j] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = true;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << "\n";

}