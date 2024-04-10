#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

void add(int& a, int b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(int& a, int b)
{
    ll c = ll(a) * ll(b);
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int binpow(int a, int n)
{
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        mul(a, a);
        n >>= 1;
    }
    return ans;
}

const int nmax = 5050;

int pref[nmax][nmax];
int dp[nmax][nmax];
int fact[2 * nmax];
int rfact[2 * nmax];

int bin(int n, int k)
{
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        s[i] = (c - 'a');
    }
    vector<int> lastpos(26, -1);

    for (int i = 1; i <= n; ++i) {
        int c = s[i];
        for (int len = 1; len <= i; ++len) {
            if (lastpos[c] != -1) {
                int val = pref[len][i - 1];
                sub(val, pref[len][lastpos[c]]);
                add(dp[len + 1][i], val);
            } else {
                int val = pref[len][i - 1];
                add(dp[len + 1][i], val);
            }
        }
        if (lastpos[c] == -1) {
            dp[1][i] = 1;
        }
        for (int len = 1; len < nmax; ++len) {
            pref[len][i] = pref[len][i - 1];
            add(pref[len][i], dp[len][i]);
        }
        lastpos[c] = i;
    }

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < 2 * nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }

    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        int sum = pref[len][n];
        int c = bin(n - 1, len - 1);
        mul(sum, c);
        add(ans, sum);
    }
    cout << ans << "\n";

}