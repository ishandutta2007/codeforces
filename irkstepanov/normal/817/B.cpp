#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

ll bin(ll n, ll k)
{
    if (k == 1) {
        return n;
    }
    if (k == 2) {
        return n * (n - 1) / 2;
    }
    if (k == 3) {
        return n * (n - 1) * (n - 2) / 6;
    }
    assert(false);
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, int> cnt;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    sort(all(a));
    map<int, int> v;
    for (int i = 0; i < 3; ++i) {
        ++v[a[i]];
    }

    ll ans = 1;
    for (auto it : v) {
        ans *= bin(cnt[it.first], it.second);
    }
    cout << ans << "\n";

}