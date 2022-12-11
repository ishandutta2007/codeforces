#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

struct datum {
	ll a, b, c;
};

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    vector<datum> ans;

    const int inf = 1e6;

    for (int i = n - 1; i >= 0; --i) {
    	if (a[i] % inf == i) {
    		continue;
    	}
    	if (a[i] < i) {
    		ll val = i - a[i];
    		ans.pb({1, i + 1, val});
    		for (int j = 0; j <= i; ++j) {
    			a[j] += val;
    		}
    		continue;
    	}
    	ll val = (i - a[i]) % inf;
    	if (val < 0) {
    		val += inf;
    	}
    	ans.pb({1, i + 1, val});
    	for (int j = 0; j <= i; ++j) {
    		a[j] += val;
    	}
    }
    ans.pb({2, n, inf});

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
    	cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << "\n";
    }

}