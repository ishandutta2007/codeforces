#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<ld, ld> pll;
typedef pair<int, int> pii;

const ll inf = 1e16;
const int max_val = 215543;

ll f(ll n)
{
    ll ans = 0;
    ll used = 0;
    for (ll val = max_val; val > 1; --val) {
        ll cnt = n / (val * val * val);
        cnt -= used;
        ans += cnt * (val - 1);
        used += cnt;
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    ll m;
    cin >> m;

    ll lf = 0, rg = inf;
    while (lf < rg - 1) {
        ll md = (lf + rg) >> 1;
        ll cnt = f(md);
        if (cnt < m) {
            lf = md;
        } else {
            rg = md;
        }
    }

    if (f(rg) != m) {
        cout << "-1\n";
    } else {
        cout << rg << "\n";
    }

}