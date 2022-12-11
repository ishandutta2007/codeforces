#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const int nmax = 40;

ll g[nmax][nmax];
ll f[nmax];

void F(int n)
{
    if (f[n] != -1) {
        return;
    }
    ll ans = 0;
    for (int v = 1; v <= n; ++v) {
        F(v - 1);
        F(n - v);
        ans += f[v - 1] * f[n - v];
    }
    f[n] = ans;
}

void G(int n, int h)
{
    if (g[n][h] != -1) {
        return;
    }
    ll ans = 0;
    if (h <= 1) {
        F(n);
        g[n][h] = f[n];
        return;
    }
    for (int v = 1; v <= n; ++v) {
        F(v - 1);
        F(n - v);
        G(v - 1, h - 1);
        G(n - v, h - 1);
        ans += f[v - 1] * g[n - v][h - 1];
        ans -= g[v - 1][h - 1] * g[n - v][h - 1];
        ans += g[v - 1][h - 1] * f[n - v];
    }
    g[n][h] = ans;
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("division.out");

    for (int i = 0; i < nmax; ++i) {
        f[i] = -1;
        for (int j = 0; j < nmax; ++j) {
            g[i][j] = -1;
        }
    }

    f[0] = g[0][0] = 1;
    for (int j = 1; j < nmax; ++j) {
        g[0][j] = 0;
    }

    int n, h;
    cin >> n >> h;

    G(n, h);
    /*for (int i = 0; i <= 3; ++i) {
        cout << "!" << i << " " << f[i] << "\n";
        for (int j = 0; j <= i; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << g[n][h] << "\n";

}