#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int inf = 1e9 + 10;

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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] > n) {
                a[i] /= 2;
            }
        }
        sort(all(a));
        bool ok = true;
        while (!a.empty()) {
            int k = sz(a);
            if (a.back() < k) {
                ok = false;
                break;
            }
            if (a.back() == k) {
                a.pop_back();
                continue;
            }
            a.back() /= 2;
            sort(all(a));
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

}