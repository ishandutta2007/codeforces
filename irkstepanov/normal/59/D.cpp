#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmax = 100 * 100 + 200;

bool dp[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> p(3 * n + 1);
    vector<int> pos(3 * n + 1);
    for (int i = 1; i <= 3 * n; ++i) {
    	cin >> p[i];
    	pos[p[i]] = i;
    }

    vector<vector<int> > a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	int cap;
    	if (pos[x] < pos[y] && pos[x] < pos[z]) {
    		a[i] = {0, x, y, z};
    	} else if (pos[y] < pos[x] && pos[y] < pos[z]) {
    		a[i] = {0, y, x, z};
    	} else {
    		a[i] = {0, z, x, y};
    	}
    }

    int k;
    cin >> k;

    int id = -1;
    for (int i = 1; i <= n; ++i) {
    	if (a[i][1] == k) {
    		id = i;
    	}
    }
    if (id == -1) {
    	for (int i = 1; i <= 3 * n; ++i) {
    		if (i == k) {
    			continue;
    		}
    		cout << i << " ";
    	}
    	cout << "\n";
    	return 0;
    }

    vector<bool> taken(3 * n + 1, false);
    for (int i = 1; i <= id; ++i) {
    	for (int j = 1; j <= 3; ++j) {
    		taken[a[i][j]] = true;
    	}
    }

    if (a[id][2] > a[id][3]) {
    	swap(a[id][2], a[id][3]);
    }
    vector<int> ans = {a[id][2], a[id][3]};
    for (int i = 1; i <= 3 * n; ++i) {
    	if (!taken[i]) {
    		ans.pb(i);
    	}
    }

    for (int j = 1; j <= 3; ++j) {
    	taken[a[id][j]] = false;
    }

    int ptr = 0;
    int x = 1;
    while (ptr < sz(ans) && x <= 3 * n) {
    	if (!taken[x]) {
    		++x;
    		continue;
    	}
    	if (ans[ptr] < x) {
    		cout << ans[ptr] << " ";
    		++ptr;
    		continue;
    	} else {
    		cout << x << " ";
    		++x;
    		continue;
    	}
    }
    while (ptr < sz(ans)) {
    	cout << ans[ptr] << " ";
    	++ptr;
    }
    while (x <= 3 * n) {
    	if (!taken[x]) {
    		++x;
    		continue;
    	}
    	cout << x << " ";
    	++x;
    }
    cout << "\n";

}