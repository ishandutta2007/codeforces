#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

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
        int n, l;
        cin >> n >> l;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int j = 0; j < l; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (bit(a[i], j)) {
                    ++cnt;
                }
            }
            if (cnt > n / 2) {
                ans |= (1 << j);
            }
        }
        cout << ans << "\n";
    }

}