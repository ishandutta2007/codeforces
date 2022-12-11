#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const ll mod = 51123987;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
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

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    string t;
    cin >> t;

    string s = "#";
    for (int i = 0; i < sz(t); ++i) {
        s += t[i];
        s += "#";
    }

    int n = sz(s);
    vector<int> d(n);

    int l = 0, r = -1;
    ll cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (i <= r) {
            d[i] = min(d[r - i + l], r - i + 1);
        }
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]]) {
            ++d[i];
        }
        cnt += d[i] / 2;
        if (i + d[i] - 1 > r) {
            r = i + d[i] - 1;
            l = i - d[i] + 1;
        }
    }

    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            --d[i];
            // add [i / 2 - d[i] / 2, i / 2]
            ++a[i / 2 - d[i] / 2];
            --a[i / 2 + 1];
            // add [i / 2, i / 2 + d[i] / 2];
            ++b[i / 2];
            --b[i / 2 + d[i] / 2 + 1];
        } else {
            d[i] -= 2;
            if (d[i] < 0) {
                continue;
            }
            // add [i / 2 - 1 - d[i] / 2, i / 2 - 1]
            ++a[i / 2 - 1 - d[i] / 2];
            --a[i / 2];
            // add [i / 2, i / 2 + d[i] / 2];
            ++b[i / 2];
            --b[i / 2 + d[i] / 2 + 1];
        }
    }

    /*for (int i = 0; i < k; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";*/

    vector<int> start(k), finish(k);
    start[0] = a[0], finish[0] = b[0];
    for (int i = 1; i < k; ++i) {
        start[i] = start[i - 1] + a[i];
        finish[i] = finish[i - 1] + b[i];
    }

    /*cout << cnt << "\n";
    for (int i = 0; i < k; ++i) {
        cout << start[i] << " " << finish[i] << "\n";
    }*/

    ll ans;
    if (cnt & 1) {
        ans = cnt % mod;
        mul(ans, ((cnt - 1) / 2) % mod);
    } else {
        ans = (cnt / 2) % mod;
        mul(ans, (cnt - 1) % mod);
    }

    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        ll val = start[i];
        mul(val, sum);
        sub(ans, val);
        add(sum, finish[i]);
    }
    cout << ans << "\n";

}