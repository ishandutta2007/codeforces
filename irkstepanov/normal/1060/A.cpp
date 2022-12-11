#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

int cnt[10];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < sz(s); ++i) {
        ++cnt[s[i] - '0'];
    }

    int ans = 0;

    for (int j = 1; j <= 100; ++j) {
        if (cnt[8] < j) {
            break;
        }
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += cnt[i];
        }
        sum -= j;
        ans = max(ans, min(j, sum / 10));
    }

    cout << ans << "\n";
    
}