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
        map<int, int> mapa;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++mapa[a[i]];
        }
        int cnt = 0;
        for (auto it : mapa) {
            cnt = max(cnt, it.second);
        }
        int ans = 0;
        while (cnt < n) {
            ++ans;
            if (2 * cnt <= n) {
                ans += cnt;
                cnt *= 2;
                continue;
            }
            int k = n - cnt;
            cnt += k;
            ans += k;
        }
        cout << ans << "\n";
    }

}