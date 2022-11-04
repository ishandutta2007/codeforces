#include<bits/stdc++.h>
#define INF 1000000000000000000ll
#define MAX 500001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll t[MAX * 4 + 7];

void update(int now, int l, int r, int l1, int r1, ll val) {
	if(l > r1 || l1 > r) {
		return;
	}
	if(l1 <= l && r <= r1) {
		t[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(now * 2, l, mid, l1, r1, val);
	update(now * 2 + 1, mid + 1, r, l1, r1, val);
}

ll get_el(int now, int l, int r, int pos) {
	if(l == r) {
		return t[now];
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		return t[now] + get_el(now * 2, l, mid, pos);
	}
	return t[now] + get_el(now * 2 + 1, mid + 1, r, pos);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi p(n);
    for(int i = 0; i < n; i++) {
    	cin >> p[i];
    }
    int m;
    cin >> m;
    vi b(m);
    for(int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    update(1, 0, n, 1, n, INF);
    for(int i = 0; i < n; i++) {
    	if(p[i] <= 0) {
    		update(1, 0, n, 0, n, p[i]);
    	}
    	int id1 = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    	if(id1 != m && b[id1] == a[i]) {
    		ll bef = get_el(1, 0, n, a[i]);
    		--id1;
    		int here = 0;
    		if(id1 >= 0) {
    			here = b[id1];
    		}
    		ll now = get_el(1, 0, n, here);
    		if(p[i] <= 0) {
    			now -= p[i];
    		}
    		if(now < bef) {
    			update(1, 0, n, a[i], a[i], now - bef);
    		}
    	}
    	if(p[i] > 0) {
    		update(1, 0, n, 0, a[i] - 1, p[i]);
    	}
    }
    ll ans = get_el(1, 0, n, b[m - 1]);
    if(ans > INF / 1000) {
    	cout << "NO";
    } else {
    	cout << "YES\n" << ans;
    }
}