#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1e7 + 100;

bool alive[nmax];

int p[nmax];
int ss[nmax];

int get(int v) {
    if (v == p[v]) {
        return v;
    }
    return (p[v] = get(p[v]));
}

void unite(int u, int v) {
    if (!alive[u] || !alive[v]) {
        return;
    }
    u = get(u), v = get(v);
    if (u == v) {
        return;
    }
    if (ss[u] < ss[v]) {
        swap(u, v);
    }
    ss[u] += ss[v];
    p[v] = u;
}

int mind[nmax];
vector<int> primes;

bool coprime(int x, int y) {
    if (x >= nmax || y >= nmax) {
        return (__gcd(x, y) == 1);
    }
    while (x > 1 && y > 1) {
        if (mind[x] == mind[y]) {
            return false;
        }
        if (mind[x] > mind[y]) {
            y /= mind[y];
        } else {
            x /= mind[x];
        }
    }
    return true;
}

bool ans[nmax];
 
int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < nmax; ++i) {
        p[i] = i;
        ss[i] = 1;
        mind[i] = i;
        alive[i] = false;
        ans[i] = false;
    }

    for (int i = 2; i < nmax; ++i) {
        if (mind[i] == i) {
            primes.pb(i);
        }
        for (int p : primes) {
            if (p * i >= nmax || p > mind[i]) {
                break;
            }
            mind[p * i] = p;
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        alive[a[i]] = true;
    }

    for (int n = 2; n < nmax / 2; ++n) {
        for (int m = 1; m <= nmax / (2 * n) && m < n; ++m) {
            ll x = ll(n) * n - ll(m) * m;
            if (2 * n * m < nmax && x < nmax) {
                ll y = ll(n) * n + ll(m) * m;
                ll z = 2 * n * m;
                if (!coprime(z, x) || !coprime(z, y) || !coprime(x, y)) {
                    continue;
                }
                unite(x, z);
                /*if (z == 2) {
                    cout << "!KEK " << n << " " << m << endl;
                }*/
                if (y < nmax) {
                    unite(x, y);
                    unite(z, y);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        ans[get(x)] = true;
        //cout << get(x) << endl;
    }
    int res = 0;
    for (int i = 0; i < nmax; ++i) {
        if (ans[i]) {
            ++res;
        }
    }
    cout << res << endl;
 
}