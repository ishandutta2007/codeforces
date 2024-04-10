#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

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

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ll opn = 0, ans = 0, mid = 0;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        add(ans, a[i] - 1);
        if (i) {
            ll y = min(a[i], a[i - 1]) - 1;
            ll z = opn;
            add(z, mid);
            mul(y, z);
            add(ans, y);
        }
        if (i && i != n - 1) {
            ll y = min(min(a[i - 1], a[i]), a[i + 1]) - 1;
            ll z = opn;
            add(z, mid);
            mul(y, z);
            mid = y;
        }
        if (i != n - 1) {
            opn = min(a[i], a[i + 1]) - 1;
        }
        //cout << opn << " " << mid << " " << ans << "\n";
    }

    cout << ans << "\n";

}