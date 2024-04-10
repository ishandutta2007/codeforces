#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> a(n);

    forn(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    ll k = sum / n;
    int cnt = n * k + n - sum;

    ll ans = 0;

    sort(all(a));
    forn(i, cnt) {
        ans += abs(k - a[i]);
    }
    for (int i = cnt; i < n; ++i) {
        ans += abs(k + 1 - a[i]);
    }

    cout << ans / 2 << "\n";

}