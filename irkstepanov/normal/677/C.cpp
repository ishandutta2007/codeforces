#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

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

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    string s;
    cin >> s;

    ll ans = 1;
    for (int i = 0; i < sz(s); ++i) {
        int k;
        if (s[i] >= '0' && s[i] <= '9') {
            k = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            k = s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            k = s[i] - 'a' + 36;
        } else if (s[i] == '-') {
            k = 62;
        } else {
            k = 63;
        }
        ll d = 0;
        for (int x = 0; x < 64; ++x) {
            int f = 0;
            for (int j = 0; j < 6; ++j) {
                if (bit(k, j)) {
                    if (!bit(x, j)) {
                        f = -1;
                        break;
                    }
                }
                if (!bit(k, j)) {
                    if (!bit(x, j)) {
                        ++f;
                    }
                }
            }
            if (f != -1) {
                add(d, (1 << f));
            }
        }
        mul(ans, d);
    }

    cout << ans << "\n";

}