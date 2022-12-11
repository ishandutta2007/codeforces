#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const ll mod = 1e6 + 3;
const int nmax = 700500;

vector<ll> fact(nmax);
vector<ll> rfact(nmax);

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

ll binpow(ll a, ll n)
{
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        if (n) {
            mul(a, a);
        }
    }
    return ans;
}

void init()
{
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }
}

ll choose(int n, int k)
{
    if (n < k) {
        return 0;
    }
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    init();

    int n, c;
    cin >> n >> c;
    ll ans = n;

    for (int i = n + 1; i < n + c; ++i) {
        ll d = choose(i, n - 1);
        //cout << i << " " << n - 1 << "\n";
        add(ans, d);
    }
    cout << ans << "\n";

}