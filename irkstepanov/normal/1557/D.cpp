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

//const int inf = 1e9;

struct node {
	int l, r;
	pii val;
	node* left;
	node* right;
	pii pro;
	node(int l, int r) : l(l), r(r), val({0, -1}), left(nullptr), right(nullptr), pro({0, -1}) {}
};

void push(node* v) {
	int tm = (v->l + v->r) >> 1;
	if (v->left == nullptr) {
		v->left = new node(v->l, tm);
	}
	if (v->right == nullptr) {
		v->right = new node(tm + 1, v->r);
	}
	v->left->val = max(v->left->val, v->pro);
	v->left->pro = max(v->left->pro, v->pro);
	v->right->val = max(v->right->val, v->pro);
	v->right->pro = max(v->right->pro, v->pro);
}

pii get(node* v, int l, int r) {
	if (v == nullptr) {
		return {0, -1};
	}
	if (v->l == l && v->r == r) {
		return v->val;
	}
	push(v);
	int tm = (v->l + v->r) >> 1;
	pii ans = {0, -1};
	if (l <= tm) {
		ans = max(ans, get(v->left, l, min(r, tm)));
	}
	if (r > tm) {
		ans = max(ans, get(v->right, max(l, tm + 1), r));
	}
	return ans;
}

node* update(node* v, int l, int r, pii& p) {
	if (v->l == l && v->r == r) {
		v->val = max(v->val, p);
		v->pro = max(v->pro, p);
		return v;
	}
	push(v);
	int tm = (v->l + v->r) >> 1;
	if (v->left == nullptr) {
		v->left = new node(v->l, tm);
	}
	if (v->right == nullptr) {
		v->right = new node(tm + 1, v->r);
	}
	if (l <= tm) {
		update(v->left, l, min(r, tm), p);
	}
	if (r > tm) {
		update(v->right, max(tm + 1, l), r, p);
	}
	v->val = max(v->val, max(v->left->val, v->right->val));
	return v;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, q;
    cin >> n >> q;

    //node* root = new node(1, inf);

    vector<vector<pii> > segs(n);
    vector<int> sorted;
    for (int i = 0; i < q; ++i) {
    	int pos, l, r;
    	cin >> pos >> l >> r;
    	--pos;
    	segs[pos].pb({l, r});
    	sorted.pb(l);
    	sorted.pb(r);
    }

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < sz(segs[i]); ++j) {
    		int x = segs[i][j].first;
    		segs[i][j].first = lower_bound(all(sorted), x) - sorted.begin();
    		int y = segs[i][j].second;
    		segs[i][j].second = lower_bound(all(sorted), y) - sorted.begin();
    	}
    }

    node* root = new node(0, sz(sorted) - 1);

    vector<pii> dp(n, {0, -1});

    for (int i = 0; i < n; ++i) {
    	for (pii& p : segs[i]) {
    		int l = p.first, r = p.second;
    		pii z = get(root, l, r);
    		++z.first;
    		dp[i] = max(dp[i], z);
    	}
    	//cout << i << endl;

    	for (pii& p : segs[i]) {
    		int l = p.first, r = p.second;
    		pii z = {dp[i].first, i};
    		root = update(root, l, r, z);
    	}
    }

   

    int best = 0;
    for (int i = 0; i < n; ++i) {
    	if (dp[i].first > dp[best].first) {
    		best = i;
    	}
    }

    cout << n - dp[best].first << "\n";

    vector<bool> good(n, false);
    while (best >= 0 && dp[best].first) {
    	good[best] = true;
    	int prev = dp[best].second;
    	best = prev;
    }

    for (int i = 0; i < n; ++i) {
    	if (!good[i]) {
    		cout << i + 1 << " ";
    	}
    }
    cout << "\n";

}