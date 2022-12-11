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

const ll mod = 1e9 + 9;

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

const int nmax = 1e6 + 10;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<ll> cnt(nmax);
    cnt[0] = 0;
    for (int i = 1; i < nmax; ++i) {
        cnt[i] = cnt[i - 1];
        add(cnt[i], 2);
        mul(cnt[i], 2);
    }

    ll ans = 1;
    for (int i = (n - 2) / 2 - 1; i >= 0; --i) {
        add(ans, 3);
        ll val = cnt[i];
        add(val, 1);
        mul(ans, val);
        add(ans, 1);
    }

    add(ans, 1);
    mul(ans, ans);
    add(ans, 1);

    mul(ans, 2);
    cout << ans << "\n";

}