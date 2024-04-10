#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

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

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

const int nmax = 300500;
ll deg[nmax];
ll pref[nmax];

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    deg[0] = 1;
    pref[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        deg[i] = deg[i - 1];
        mul(deg[i], 2);
        pref[i] = pref[i - 1];
        add(pref[i], deg[i]);
    }

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll s = 0;
        if (i) {
            add(s, pref[i - 1]);
        }
        if (i < n - 1) {
            sub(s, pref[n - i - 2]);
        }
        mul(s, a[i]);
        add(ans, s);
    }

    cout << ans << "\n";

}