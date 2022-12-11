#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int nmax = 200500;

int mind[nmax];
vector<int> primes;

int grundy[nmax];
bitset<nmax> g[100];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < nmax; ++i) {
        mind[i] = i;
    }

    for (int i = 2; i < nmax; ++i) {
        if (i == mind[i]) {
            primes.pb(i);
        }
        for (int p : primes) {
            if (i * p >= nmax || p > mind[i]) {
                break;
            }
            mind[p * i] = p;
        }
    }

    bitset<nmax> p;
    for (int i = 2; i < nmax; ++i) {
        if (mind[i] == i) {
            p[i] = 1;
        } else {
            int j = i / mind[i];
            if (j == mind[j]) {
                p[i] = 1;
            }
        }
    }

    int q, bad;
    cin >> q >> bad;
    p[bad] = 0;

    g[0] = p;

    for (int i = 1; i < nmax; ++i) {
        while (g[grundy[i]][i]) {
            ++grundy[i];
        }
        g[grundy[i]] |= (p << i);
    }

    int ans = 0;

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        ans ^= grundy[b - a - 1];
        ans ^= grundy[c - b - 1];
    }

    string s[2] = {"Alice", "Bob"};
    if (ans == 0) {
        swap(s[0], s[1]);
    }
    cout << s[0] << " " << s[1] << "\n";

}