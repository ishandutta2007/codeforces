#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = (int)2e18;
struct Line {
	int m, c;
	int eval(int x) {
		return m * x + c;
	}
};
struct node {
	Line line;
	node* left = nullptr;
	node* right = nullptr;
	node(Line line) : line(line) {}
	void add_segment(Line nw, int l, int r, int L, int R) {
		if (l > r || r < L || l > R) return;
		int m = (l + 1 == r ? l : (l + r) / 2);
		if (l >= L and r <= R) {
			bool lef = nw.eval(l) < line.eval(l);
			bool mid = nw.eval(m) < line.eval(m);
			if (mid) swap(line, nw);
			if (l == r) return;
			if (lef != mid) {
				if (left == nullptr) left = new node(nw);
				else left -> add_segment(nw, l, m, L, R);
			}
			else {
				if (right == nullptr) right = new node(nw);
				else right -> add_segment(nw, m + 1, r, L, R);
			}
			return;
		}
		if (max(l, L) <= min(m, R)) {
			if (left == nullptr) left = new node({0, inf});
			left -> add_segment(nw, l, m, L, R);
		}
		if (max(m + 1, L) <= min(r, R)) {
			if (right == nullptr) right = new node ({0, inf});
			right -> add_segment(nw, m + 1, r, L, R);
		}
	}
	int query_segment(int x, int l, int r, int L, int R) {
		if (l > r || r < L || l > R) return inf;
		int m = (l + 1 == r ? l : (l + r) / 2);
		if (l >= L and r <= R) {
			int ans = line.eval(x);
			if (l < r) {
				if (x <= m && left != nullptr) ans = min(ans, left -> query_segment(x, l, m, L, R));
				if (x > m && right != nullptr) ans = min(ans, right -> query_segment(x, m + 1, r, L, R));
			}
			return ans;
		}
		int ans = inf;
		if (max(l, L) <= min(m, R)) {
			if (left == nullptr) left = new node({0, inf});
			ans = min(ans, left -> query_segment(x, l, m, L, R));
		}
		if (max(m + 1, L) <= min(r, R)) {
			if (right == nullptr) right = new node ({0, inf});
			ans = min(ans, right -> query_segment(x, m + 1, r, L, R));
		}
		return ans;
	}
};

struct LiChaoTree {// the input values for lichaotree are boundaries of x values you can use to query with
	int L, R;
	node* root;
	LiChaoTree() : L(numeric_limits<int>::min() / 2), R(numeric_limits<int>::max() / 2), root(nullptr) {}
	LiChaoTree(int L, int R) : L(L), R(R) {
		root = new node({0, inf});
	}
	void add_line(Line line) {
		root -> add_segment(line, L, R, L, R);
	}
	// y = mx + b: x in [l, r]
	void add_segment(Line line, int l, int r) {
		root -> add_segment(line, L, R, l, r);
	}
	int query(int x) {
		return root -> query_segment(x, L, R, L, R);
	}
	int query_segment(int x, int l, int r) {
		return root -> query_segment(x, l, r, L, R);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>a(n+1);
	vector<int>psa(n+1);
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		psa[i] = psa[i-1]+a[i];
	}
	int mx = 0;
	if(true){
		LiChaoTree t(-(int)1e9,(int)1e9);
		t.add_line({-a[1],0});
		vector<int>dp(n+1);
		
		for(int i = 2; i<=n; i++){
			dp[i] = t.query(i)+psa[i];
			dp[i]*=-1;
			t.add_line({-a[i],i*a[i]-psa[i]});
			mx = max(mx,dp[i]);
		}
	}
	//cout << mx << "\n";
	if(true){
		LiChaoTree t(-(int)1e9,(int)1e9);
		t.add_line({-a[n],n*a[n] - psa[n]+a[n]});
		vector<int>dp(n+1);
		for(int i = n-1; i>=1; i--){
			dp[i] = t.query(i)+psa[i]-a[i];
			dp[i]*=-1;
			t.add_line({-a[i],i*a[i]-psa[i]+a[i]});
			mx = max(mx,dp[i]);
		}
	}
	//cout << mx << "\n";
	int ans = mx;
	for(int i = 1; i<=n; i++){
		ans+=a[i]*i;
	}
	cout << ans << "\n";
	return 0;
}