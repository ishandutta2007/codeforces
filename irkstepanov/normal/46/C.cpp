#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
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

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T') {
            ++cnt;
        }
    }

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < cnt; ++i) {
        if (s[i] == 'T') {
            ++curr;
        }
    }
    ans = max(ans, curr);

    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'T') {
            --curr;
        }
        if (s[(i + cnt - 1) % n] == 'T') {
            ++curr;
        }
        ans = max(ans, curr);
    }

    cout << cnt - ans << "\n";
    

}