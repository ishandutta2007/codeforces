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

const int amax = 1e6 + 50;
const int nmax = 2e5 + 50;
const int mod = 1e9 + 7;

int add(int& a, int b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mul(int& a, int b)
{
    ll c = (ll)(a) * (ll)(b);
    a = c % mod;
}

int binpow(int a, int n)
{
    int ans = 1;
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

vector<int> fact(nmax), rfact(nmax);

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    vector<vector<int> > divisors(amax);
    for (int i = 1; i < amax; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                divisors[i].pb(j);
                if (j * j != i) {
                    divisors[i].pb(i / j);
                }
            }
        }
    }

    vector<int> phi(amax);
    for (int i = 1; i < amax; ++i) {
        phi[i] = i;
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                phi[i] /= j;
                phi[i] *= (j - 1);
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x != 1) {
            phi[i] /= x;
            phi[i] *= (x - 1);
        }
    }

    fact[0] = rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }

    vector<int> cnt(amax);

    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);

    vector<int> choose(nmax);
    for (int i = k - 1; i < nmax; ++i) {
        choose[i] = fact[i];
        mul(choose[i], rfact[k - 1]);
        mul(choose[i], rfact[i - (k - 1)]);
    }

    int ans = 0;

    for (int i = 0; i < n + q; ++i) {
        int val;
        scanf("%d", &val);
        for (int d : divisors[val]) {
            int relax = phi[d];
            mul(relax, choose[cnt[d]]);
            add(ans, relax);
            ++cnt[d];
        }
        if (i >= n) {
            printf("%d\n", ans);
        }
    }

}