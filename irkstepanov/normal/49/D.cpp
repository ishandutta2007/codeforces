#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    string init = s;
    int ans = 100500;

    for (int st = 0; st < 2; ++st) {
        string goal = "";
        s = init;
        for (int i = 0; i < n; ++i) {
            goal += char((i + st) % 2 + '0');
        }
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == goal[i]) {
                continue;
            }
            ++curr;
        }
        ans = min(ans, curr);
    }

    cout << ans << "\n";
    
}