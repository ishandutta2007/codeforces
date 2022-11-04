#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<int> t;
vector<int> lp;

void add(int now, int l, int r, int l1, int r1, int val) {
	if(l > r1 || l1 > r) {
		return;
	}
	if(l1 <= l && r <= r1) {
		lp[now] += val;
		t[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	add(now * 2, l, mid, l1, r1, val);
	add(now * 2 + 1, mid + 1, r, l1, r1, val);
	t[now] = max(t[now * 2], t[now * 2 + 1]) + lp[now];
}
int get_max(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) {
		return 0;
	}
	if(l1 <= l && r <= r1) {
		return t[now];
	}
	int mid = (l + r) / 2;
	return max(get_max(now * 2, l, mid, l1, r1), get_max(now * 2 + 1, mid + 1, r, l1, r1)) + lp[now];
}

int get_id1(int now, int l, int r, int val, int adding=0) {
	if(adding + t[now] < val) {
		return -1;
	}
	if(l == r) {
		return l;
	}
	adding += lp[now];
	int mid = (l + r) / 2;
	if(adding + t[now * 2 + 1] >= val) {
		return get_id1(now * 2 + 1, mid + 1, r, val, adding);
	}
	return get_id1(now * 2, l, mid, val, adding);
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	--a[i];
    }
    t.assign(4 * n + 7, 0);
    lp.assign(4 * n + 7, 0);
    vi ans(q);
    vector<vector<pair<int, int>>> query(n);
    for(int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	query[n - 1 - y].push_back({x, i});
    }
    for(int i = 0; i < n; i++) {
    	int need = i - a[i];
    	if(need >= 0) {
    		int res = get_id1(1, 0, n - 1, need);
    		res = min(res, i);
    		if(res != -1) {
    			add(1, 0, n - 1, 0, res, 1);
    		}
    	}
    	for(auto& q : query[i]) {
    		ans[q.second] = get_max(1, 0, n - 1, q.first, q.first);
    	}
    }
    for(int i = 0; i < q; i++) {
    	cout << ans[i] << '\n';
    }
}