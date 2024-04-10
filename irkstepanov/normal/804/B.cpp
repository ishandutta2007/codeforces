#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
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

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    ll val = 1;
    ll ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == 'a') {
            add(val, val);
        } else {
            add(ans, val);
            sub(ans, 1);
        }
    }

    cout << ans << "\n";

}