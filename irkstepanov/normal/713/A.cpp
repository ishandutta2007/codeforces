#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int inf = 1e9;

ll p(ll val)
{
    vector<int> d;
    while (val) {
        d.pb(val % 2);
        val /= 10;
    }
    reverse(all(d));
    ll ans = 0;
    for (int i = 0; i < sz(d); ++i) {
        ans <<= 1;
        ans += d[i];
    }
    return ans;
}

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("wa9.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int q;
    cin >> q;

    map<ll, int> m;

    while (q--) {
        char type;
        cin >> type;
        if (type == '+' || type == '-') {
            ll val;
            cin >> val;
            ll x = p(val);
            if (type == '+') {
                ++m[x];
            } else {
                --m[x];
            }
        } else {
            string s;
            cin >> s;
            ll x = 0;
            for (int i = 0; i < sz(s); ++i) {
                x <<= 1;
                x += (s[i] - '0');
            }
            if (!m.count(x)) {
                cout << "0\n";
            } else {
                cout << m[x] << "\n";
            }
            cout.flush();
        }
    }

}