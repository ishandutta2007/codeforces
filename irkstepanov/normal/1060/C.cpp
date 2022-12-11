#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

vector<ll> build(vector<ll> a) {
	int n = sz(a);
	vector<ll> ans(n + 1);
	for (int len = 1; len <= n; ++len) {
		ll sum = 0;
		for (int i = 0; i < len; ++i) {
			sum += a[i];
		}
		ans[len] = sum;
		for (int i = len; i < n; ++i) {
			sum += a[i];
			sum -= a[i - len];
			ans[len] = min(ans[len], sum);
		}
	}
	return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
   	cin >> n >> m;

   	vector<ll> a(n);
   	for (int i = 0; i < n; ++i) {
   		cin >> a[i];
   	}

   	vector<ll> x = build(a);

   	vector<ll> b(m);
   	for (int i = 0; i < m; ++i) {
   		cin >> b[i];
   	}

   	vector<ll> y = build(b);

   	ll z;
   	cin >> z;
   	int ans = 0;

   	for (int l1 = 1; l1 <= n; ++l1) {
   		for (int l2 = 1; l2 <= m; ++l2) {
   			ll t = x[l1] * y[l2];
   			if (t <= z) {
   				ans = max(ans, l1 * l2);
   			}
   		}
   	}

   	cout << ans << "\n";
    
}