#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

ll rev(ll a, int size)
{
    ll ans = 0;
    while (size--) {
        ans <<= 1;
        ans += (a & 1);
        a >>= 1;
    }
    return ans;
}

void out(ll x, int size)
{
    vector<int> ans;
    while (size--) {
        ans.pb(x % 2);
        x /= 2;
    }
    reverse(all(ans));
    for (int y : ans) {
        cout << y;
    }
    cout << "\n";
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll num;
    cin >> n >> num;
    ++num;
    int k = (n + 1) / 2;

    ll a = 0;
    for (a = 0; a < (1LL << (k - 1)); ++a) {
        if (!(n & 1)) {
            ll cnt = 2 * ((1LL << (k - 1)) - a);
            if (num > cnt) {
                num -= cnt;
            } else {
                break;
            }
        } else {
            ll cnt = (1LL << (k - 2)) - a / 2;
            if (!(a & 1)) {
                cnt *= 2;
            } else {
                cnt *= 2;
                --cnt;
            }
            if (num > cnt) {
                num -= cnt;
            } else {
                break;
            }
        }
    }
    
    if (a == (1 << (k - 1))) {
        cout << "-1\n";
        return 0;
    }
    
    ll maxx = (1LL << n) - 1;

    if (!(n & 1)) {
        ll ra = rev(a, k);
        for (ll b = 0; ; ++b) {
            ll rb = rev(b, k);
            ll x = (a << k) + b;
            ll rx = (rb << k) + ra;
            if (x > rx) {
                continue;
            }
            ll irx = maxx ^ rx;
            if (x > irx) {
                continue;
            }
            --num;
            if (num == 0) {
                out(x, n);
                return 0;
            }
        }
    } else {
        for (ll b = 0; ; ++b) {
            ll x = (a << (k - 1)) + b;
            ll rx = rev(x, n);
            if (x > rx) {
                continue;
            }
            ll irx = maxx ^ rx;
            if (x > irx) {
                continue;
            }
            --num;
            if (num == 0) {
                out(x, n);
                return 0;
            }
        }
    }

}