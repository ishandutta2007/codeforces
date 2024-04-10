#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    n *= 2;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    vector<int> to(n, -1);
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	to[u] = v;
    	to[v] = u;
    }

    int player;
    cin >> player;

    vector<bool> used(n, false);
    int cnt = 0;
    int pr = -1;
    if (player == 2) {
    	cin >> pr;
    	--pr;
    	used[pr] = true;
    	++cnt;
    }

    while (cnt < n) {
    	int x = -1;
    	if (pr != -1) {
    		x = to[pr];
    	}
    	if (x != -1 && !used[x]) {
    		used[x] = true;
    		cout << x + 1 << endl;
    		++cnt;
    		if (cnt == n) {
    			return 0;
    		}
    		cin >> pr;
    		--pr;
    		used[pr] = true;
    		++cnt;
    		continue;
    	}
    	x = -1;
    	for (int i = 0; i < n; ++i) {
    		if (used[i] || to[i] == -1) {
    			continue;
    		}
    		if (x == -1 || a[i] > a[x]) {
    			x = i;
    		}
    	}
    	if (x != -1) {
    		used[x] = true;
    		cout << x + 1 << endl;
    		++cnt;
    		cin >> pr;
    		--pr;
    		++cnt;
    		used[pr] = true;
    		continue;
    	}
    	for (int i = 0; i < n; ++i) {
    		if (used[i]) {
    			continue;
    		}
    		if (x == -1 || a[i] > a[x]) {
    			x = i;
    		}
    	}
    	used[x] = true;
    	cout << x + 1 << endl;
    	++cnt;
    	if (cnt == n) {
    		return 0;
    	}
    	cin >> pr;
    	--pr;
    	++cnt;
    	used[pr] = true;
    }

}