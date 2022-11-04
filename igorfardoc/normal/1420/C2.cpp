#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
struct Node {
	ll min0;
	ll min1;
	ll max0;
	ll max1;
};
vector<Node> tree;
void update(int i) {
	tree[i].min0 = min(tree[i * 2].min0, tree[i * 2 + 1].min0);
	tree[i].min1 = min(tree[i * 2].min1, tree[i * 2 + 1].min1);
	tree[i].max0 = max(tree[i * 2].max0, tree[i * 2 + 1].max0);
	tree[i].max1 = max(tree[i * 2].max1, tree[i * 2 + 1].max1);

	tree[i].min0 = min(tree[i].min0, min(tree[i * 2].min0 + tree[i * 2 + 1].min0, tree[i * 2].min1 - tree[i * 2 + 1].max1));
	tree[i].max0 = max(tree[i].max0, max(tree[i * 2].max0 + tree[i * 2 + 1].max0, tree[i * 2].max1 - tree[i * 2 + 1].min1));
	tree[i].min1 = min(tree[i].min1, min(tree[i * 2].min0 + tree[i * 2 + 1].min1, tree[i * 2].min1 - tree[i * 2 + 1].max0));
	tree[i].max1 = max(tree[i].max1, max(tree[i * 2].max0 + tree[i * 2 + 1].max1, tree[i * 2].max1 - tree[i * 2 + 1].min0));
}

void build(int now, int l, int r, vi& a) {
	if(l == r) {
		tree[now].min0 = 0;
		tree[now].max0 = 0;
		tree[now].min1 = a[l];
		tree[now].max1 = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(now * 2, l, mid, a);
	build(now * 2 + 1, mid + 1, r, a);
	update(now);
}

void update1(int now, int l, int r, int pos, int val) {
	if(l == r) {
		tree[now].min0 = 0;
		tree[now].max0 = 0;
		tree[now].min1 = val;
		tree[now].max1 = val;
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update1(now * 2, l, mid, pos, val);
	} else {
		update1(now * 2 + 1, mid + 1, r, pos, val);
	}
	update(now);
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
    int t;
    cin >> t;
    while(t--) {
    	int n, q;
    	cin >> n >> q;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	tree.resize(4 * n + 3);
    	build(1, 0, n - 1, a);
    	cout << max(tree[1].max1, tree[1].max0) << '\n';
    	for(int i = 0; i < q; i++) {
    		int l, r;
    		cin >> l >> r;
    		--l;
    		--r;
    		if(l != r) {
    			int temp = a[l];
    			a[l] = a[r];
    			a[r] = temp;
    			update1(1, 0, n - 1, l, a[l]);
    			update1(1, 0, n - 1, r, a[r]);
    		}
    		cout << max(tree[1].max1, tree[1].max0) << '\n';
    	}
    }
}