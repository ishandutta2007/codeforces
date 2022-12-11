#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int cnt1, x;
    int cnt2, y;
    cin >> cnt1 >> x >> cnt2 >> y;

    if (x > y) {
        swap(x, y);
        swap(cnt1, cnt2);
    }

    ll ans = cnt1 + 1;
    for (int i = 1; i <= cnt2; ++i) {
        if (y - i >= x + cnt1) {
            ++ans;
            continue;
        }
        if (y - i <= x - cnt1) {
            ++ans;
            continue;
        }
        if (y - i >= x - cnt1 && y + i <= x + cnt1) {
            if (y - i >= x) {
                ans += ll(i * 4) - 2;
            } else {
                ans += ll(y - x) * 4 - 1;
            }
            continue;
        }
        if (y - i >= x) {
            ll d = (x + cnt1) - (y - i);
            ans += d * 2;
        } else {
            ll d = (y - i) - (x - cnt1);
            ans += d * 2 + 1;
        }
    }

    cout << ans << "\n";

}