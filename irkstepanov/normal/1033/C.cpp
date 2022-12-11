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

    vector<int> a(n);
    vector<pii> sorted;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted.pb({a[i], i});
    }
    sort(all(sorted));
    reverse(all(sorted));

    vector<bool> win(n, false);
    for (int pos = 0; pos < n; ++pos) {
        int i = sorted[pos].second;
        for (int d = a[i]; d < n; d += a[i]) {
            int j = i - d;
            if (j >= 0 && a[j] > a[i] && !win[j]) {
                win[i] = true;
            }
            j = i + d;
            if (j < n && a[j] > a[i] && !win[j]) {
                win[i] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (win[i] ? 'A' : 'B');
    }
    cout << "\n";
    
}