#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii conv(char c) {
    if (c == 'R') {
        return {1, 0};
    } else if (c == 'L') {
        return {-1, 0};
    } else if (c == 'U') {
        return {0, 1};
    } else {
        return {0, -1};
    }
}

pii operator+(pii a, pii b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;
    if (abs(x) + abs(y) > sz(s) || (abs(x) + abs(y)) % 2 != sz(s) % 2) {
        cout << "-1\n";
        return 0;
    }

    vector<pii> suff(n + 1);
    suff[n] = {0, 0};
    suff[n - 1] = conv(s[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = conv(s[i]) + suff[i + 1];
    }

    int ans = n;
    pii start = {0, 0};
    for (int i = 0; i <= n; ++i) {
        int dx = x - start.first, dy = y - start.second;
        int rem = n - i;
        if (abs(dx) + abs(dy) <= rem) {
            int lf = i - 1, rg = n;
            while (rg - lf > 1) {
                int md = (lf + rg) >> 1;
                int a = x - start.first - suff[md].first;
                int b = y - start.second - suff[md].second;
                if (abs(a) + abs(b) > md - i) {
                    lf = md;
                } else {
                    rg = md;
                }
            }
            //cout << i << " " << rg << endl;
            int a = x - start.first - suff[rg].first;
            int b = y - start.second - suff[rg].second;
            if (abs(a) + abs(b) <= rg - i) {
                ans = min(ans, rg - i);
            }
        }
        start = start + conv(s[i]);
    }

    cout << ans << "\n";

}