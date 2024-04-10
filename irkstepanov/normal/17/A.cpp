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

const int nmax = 1050;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    vector<char> p(nmax, true);
    vector<int> primes;

    for (int i = 2; i < nmax; ++i) {
        if (p[i]) {
            primes.pb(i);
            for (int j = 2 * i; j < nmax; j += i) {
                p[j] = false;
            }
        }
    }

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = 0; i < sz(primes) - 1; ++i) {
        int val = primes[i] + primes[i + 1] + 1;
        if (val <= n && p[val]) {
            //cout << primes[i] + primes[i + 1] + 1  << "\n";
            ++cnt;
        }
    }

    cout << (cnt >= k ? "YES\n" : "NO\n");

}