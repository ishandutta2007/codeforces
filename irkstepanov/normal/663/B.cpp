#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

ll deg(int d)
{
    ll ans = 1;
    for (int i = 0; i < d; ++i) {
        ans *= (ll)(10);
    }
    return ans;
}

string conv(ll x)
{
    if (!x) {
        return "0";
    }
    string s = "";
    while (x) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(all(s));
    return s;
}

ll conv(const string& s)
{
    ll ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans *= 10;
        ans += (s[i] - '0');
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;
        ll n = 0;
        for (int i = 4; i < sz(s); ++i) {
            n *= 10;
            n += (s[i] - '0');
        }
        ll k = 1989;
        for (int i = sz(s) - 1; i >= 4; --i) {
            ll suff = 0;
            string b = "";
            for (int j = i; j < sz(s); ++j) {
                suff *= 10;
                suff += (s[j] - '0');
                b += s[j];
            }
            if (suff >= k) {
                k = suff + 1;
                continue;
            }
            string a = conv(k);
            string t = "";
            for (int i = 0; i < sz(a) - sz(b); ++i) {
                t += a[i];
            }
            for (int i = 0; i < sz(b); ++i) {
                t += b[i];
            }
            ll x = conv(t);
            //cout << x << " " << t << "\n";
            if (x >= k) {
                k = x + 1;
            } else {
                x += deg(sz(b));
                k = x + 1;
            }
            //cout << k << "\n";
        }
        cout << k - 1 << "\n";
    }

}