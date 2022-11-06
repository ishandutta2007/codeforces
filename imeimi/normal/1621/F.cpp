#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

ll solve(int s, int a, int b, int c, vector<pii> Zero, int OneSum) {
    ll ans = 0, sum = 0;
    int bonus0 = 0, bonus1 = 0, valid = 0;
    for (int i = s; ; ++i) {
        if (i & 1) {
            if (OneSum) {
                sum += b;
                OneSum -= 1;
            }
            else if (bonus1) {
                sum += b;
                bonus1 -= 1;
            }
            else break;
        }
        else {
            while (!Zero.empty() && !Zero.back().se) {
                bonus0 += 1;
                valid += Zero.back().fs;
                Zero.pop_back();
            }
            if (!Zero.empty()) {
                if (!OneSum && !bonus1 && valid) {
                    ans = max(ans, sum + a);
                    sum -= c;
                    bonus0 -= 1;
                    bonus1 += 1;
                    valid -= 1;
                    continue;
                }
                sum += a;
                if (!(Zero.back().se += 1)) {
                    bonus0 += 1;
                    valid += Zero.back().fs;
                    Zero.pop_back();
                }
            }
            else if (bonus0) {
                sum -= c;
                bonus0 -= 1;
                if (valid) bonus1 += 1, valid -= 1;
            }
            else break;
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, a, b, c;
        string s;
        cin >> n >> a >> b >> c >> s;
        vector<pii> S(1, pii(s[0], 0));
        for (char c : s) {
            if (S.back().fs == c) ++S.back().se;
            else S.emplace_back(c, 1);
        }
        vector<pii> Zero;
        for (int i = 0; i < int(S.size()); ++i) {
            if (S[i].fs != '0') continue;
            Zero.emplace_back(0 < i && i < int(S.size()) - 1, -(S[i].se - 1));
        }
        sort(Zero.begin(), Zero.end());
        int OneSum = 0;
        for (auto [chr, cnt] : S) {
            if (chr != '1') continue;
            OneSum += cnt - 1;
        }
        ll ans0 = solve(0, a, b, c, Zero, OneSum);
        ll ans1 = solve(1, a, b, c, Zero, OneSum);
        printf("%lld\n", max(ans0, ans1));
    }
    return 0;
}