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

const int sigma = 26;

int cnt[sigma];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    string t = "";
    for (int i = 0; i < sigma; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            t += char(i + 'a');
        }
    }
    cout << t << endl;

    /*int cnt = 0;
    for (int i = 0; i < sz(t); ++i) {
        for (int j = i; j < sz(t); ++j) {
            bool ok = true;
            for (int k = i, r = j; k <= j; ++k, --r) {
                if (t[k] != t[r]) {
                    ok = false;
                }
            }
            if (ok) {
                ++cnt;
            }
        }
    }
    cout << cnt << "\n";*/
    
}