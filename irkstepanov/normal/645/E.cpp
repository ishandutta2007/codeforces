#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int main()
{

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> v(k);
    vector<int> pos(k, -1);
    ll sum = 0;
    for (int i = 0; i < sz(s); ++i) {
        pos[s[i] - 'a'] = i;
        ll val = sum;
        add(val, 1);
        ll x = val;
        sub(x, v[s[i] - 'a']);
        add(sum, x);
        v[s[i] - 'a'] = val;
    }

    for (int i = 0; i < n; ++i) {
        int t = 0;
        for (int j = 1; j < k; ++j) {
            if (pos[j] < pos[t]) {
                t = j;
            }
        }
        pos[t] = sz(s) + i;
        ll val = sum;
        add(val, 1);
        ll x = val;
        sub(x, v[t]);
        add(sum, x);
        v[t] = val;
    }

    add(sum, 1);
    cout << sum << "\n";

}