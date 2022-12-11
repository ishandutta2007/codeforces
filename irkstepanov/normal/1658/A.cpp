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
        string s;
        cin >> s;
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                pos.pb(i);
            }
        }
        int ans = 0;
        for (int i = 1; i < sz(pos); ++i) {
            if (pos[i] - pos[i - 1] == 1) {
                ans += 2;
            } else if (pos[i] - pos[i - 1] == 2) {
                ans += 1;
            }
        }
        cout << ans << "\n";
    }

}