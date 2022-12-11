#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

vector<ll> ans(1010, inf);
vector<int> primes;

void rec(int pos, int deg, ll val, int cnt)
{
    if (pos == sz(primes)) {
        return;
    }
    ans[cnt] = min(ans[cnt], val);
    ll x = primes[pos];
    for (int i = 1; i <= deg; ++i) {
        int cnt_new = cnt * (i + 1);
        if (cnt_new > 1010) {
            break;
        }
        ll val_new = val * x;
        if (x > (inf / val)) {
            break;
        }
        rec(pos + 1, i, val_new, cnt_new);
        x *= primes[pos];
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    vector<char> p(100, true);
    ans[1] = 1;

    for (int i = 2; i < 100; ++i) {
        if (p[i]) {
            primes.pb(i);
            for (int j = 2 * i; j < 100; j += i) {
                p[j] = false;
            }
        }
    }

    for (int i = 1; i <= 63; ++i) {
        rec(1, i, (1LL << i), i + 1);
    }

    int n;
    cin >> n;
    cout << ans[n] << "\n";

}