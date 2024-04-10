#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll inf = 5e18;

int main() {

    //ifstream cin("input.txt");
    //freopen("defend.out", "w", stdout);
    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefMin(n), prefMax(n);
    prefMin[0] = prefMax[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefMin[i] = min(prefMin[i - 1], a[i]);
        prefMax[i] = max(prefMax[i - 1], a[i]);
    }

    vector<ll> suffMin(n), suffMax(n);
    suffMin[n - 1] = suffMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffMin[i] = min(suffMin[i + 1], a[i]);
        suffMax[i] = max(suffMax[i + 1], a[i]);
    }

    ll ans = -inf;

    for (int i = 0; i < n; ++i) {
        ll curr = q * a[i];
        curr += max(prefMin[i] * p, prefMax[i] * p);
        curr += max(suffMin[i] * r, suffMax[i] * r);
        ans = max(ans, curr);
    }

    cout << ans << "\n";

}