#include<bits/stdc++.h>
#define INF 2000000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
struct Node {
	vi v;
	int ans;
};

Node join(Node a, Node b) {
	Node res;
	res.ans = min(a.ans, b.ans);
	res.v.assign(10, INF);
	for(int i = 0; i < 9; i++) {
		if(a.v[i] != INF && b.v[i] != INF) {
			res.ans = min(res.ans, a.v[i] + b.v[i]);
		}
		res.v[i] = min(a.v[i], b.v[i]);
	}
	return res;
}

Node build_node(int a) {
	Node res;
	res.ans = INF;
	int now = a;
	res.v.assign(10, INF);
	for(int i = 0; i < 10; i++) {
		int here = now % 10;
		if(here != 0) {
			res.v[i] = a;
		}
		now /= 10;
	}
	return res;
}

Node build_empty() {
	Node res;
	res.ans = INF;
	res.v.assign(10, INF);
	return res;
}

vi a;
vector<Node> t;

void build(int now, int l, int r) {
	if(l == r) {
		t[now] = build_node(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(now * 2, l, mid);
	build(now * 2 + 1, mid + 1, r);
	t[now] = join(t[now * 2], t[now * 2 + 1]);
	//cout << l << ' ' << r << ' ' << t[now].ans << endl;
}

Node q(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) {
		return build_empty();
	}
	if(l1 <= l && r <= r1) {
		return t[now];
	}
	int mid = (l + r) / 2;
	return join(q(now * 2, l, mid, l1, r1), q(now * 2 + 1, mid + 1, r, l1, r1));
}
void update(int now, int l, int r, int pos) {
	if(l == r) {
		t[now] = build_node(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(now * 2, l, mid, pos);
	} else {
		update(now * 2 + 1, mid + 1, r, pos);
	}
	t[now] = join(t[now * 2], t[now * 2 + 1]);
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
    int n, m;
    cin >> n >> m;
    t.resize(4 * n + 7);
    a.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    build(1, 0, n - 1);
    for(int i = 0; i < m; i++) {
    	int t, b, c;
    	cin >> t >> b >> c;
    	if(t == 1) {
    		--b;
    		a[b] = c;
    		update(1, 0, n - 1, b);
    	} else {
    		--b;
    		--c;
    		auto res = q(1, 0, n - 1, b, c);
    		if(res.ans == INF) {
    			cout << -1 << '\n';
    		} else {
    			cout << res.ans << '\n';
    		}
    	}
    }
}