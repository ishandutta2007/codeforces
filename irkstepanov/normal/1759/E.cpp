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

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        ll init;
        cin >> n >> init;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        int ans = 0;
        vector<int> cnt = {2, 2, 3};
        do {
            int ptr = 0;
            ll h = init;
            for (int i = 0; i < 3; ++i) {
                while (ptr < n && a[ptr] < h) {
                    h += (a[ptr] / 2);
                    ++ptr;
                }
                h *= cnt[i];
                while (ptr < n && a[ptr] < h) {
                    h += (a[ptr] / 2);
                    ++ptr;
                }
            }
            ans = max(ans, ptr);
        } while (next_permutation(all(cnt)));
        cout << ans << "\n";
    }

}