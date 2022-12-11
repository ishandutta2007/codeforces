#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

vector<ll> dp;
vector<ll> prom;

void push(int v) {
	dp[v * 2] += prom[v];
	dp[v * 2 + 1] += prom[v];
	prom[v * 2] += prom[v];
	prom[v * 2 + 1] += prom[v];
	prom[v] = 0;
}

ll get(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		return dp[v];
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		return get(v * 2, tl, tm, pos);
	} else {
		return get(v * 2 + 1, tm + 1, tr, pos);
	}
}

void update(int v, int tl, int tr, int l, int r, ll val) {
	if (tl == l && tr == r) {
		dp[v] += val;
		prom[v] += val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		update(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	dp[v] = min(dp[v * 2], dp[v * 2 + 1]);
}

const ll inf = 1e18;

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n);
    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	cin >> cost[i];
    }

    int m;
    cin >> m;
    vector<ll> b(m + 1);
    b[0] = 0;
    for (int i = 1; i <= m; ++i) {
    	cin >> b[i];
    }

    dp = vector<ll>(4 * (m + 1), 0);
    prom = vector<ll>(4 * (m + 1), 0);
    update(1, 0, m, 1, m, inf);
    
    for (int i = 0; i < n; ++i) {
    	int k = lower_bound(all(b), a[i]) - b.begin();
    	if (k == m + 1) {
    		prom[1] += cost[i];
    		dp[1] += cost[i];
    		continue;
    	}
    	if (a[i] != b[k]) {
    		update(1, 0, m, 0, k - 1, cost[i]);
    		if (cost[i] < 0) {
    			update(1, 0, m, k, m, cost[i]);
    		}
    	} else {
    		ll x = get(1, 0, m, k - 1);
    		ll curr = get(1, 0, m, k);
    		ll opt = min(x, curr + min(ll(0), cost[i]));
    		if (opt < curr) {
    			update(1, 0, m, k, k, opt - curr);
    		}
    		update(1, 0, m, 0, k - 1, cost[i]);
    		if (cost[i] < 0 && k + 1 <= m) {
    			update(1, 0, m, k + 1, m, cost[i]);
    		}
    	}
    }

    ll val = get(1, 0, m, m);
    //ll l = 1e18 - 1e9 * 6 * 1e5;
    //cout << l << endl;
    if (val > 1e9 * 6 * 1e5) {
    	cout << "NO\n";
    } else {
    	cout << "YES\n";
    	cout << val << "\n";
    }

}