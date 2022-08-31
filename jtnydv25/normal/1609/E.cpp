#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif
#define int long long
const int INF = 1e16;

struct Data{
	int mn_ab, mn_bc, val;
	int l1, l2;
	Data(){mn_ab = mn_bc = 0; val = INF; l1 = l2 = 0;}
	void push(){
		mn_ab += l1; mn_bc += l2; val += l1 + l2;
		l1 = l2 = 0;
	}
};

Data merge(const Data& a, const Data& b){
	Data ret;
	ret.mn_ab = min(a.mn_ab, b.mn_ab);
	ret.mn_bc = min(a.mn_bc, b.mn_bc);
	ret.val = min(a.val, min(b.val, a.mn_ab + b.mn_bc));
	return ret;
}

const int MAXN = 100005;

int pref_ab[MAXN], pref_bc[MAXN];

struct segtree{
	int n;
	vector<Data> tree;
	segtree(int n): tree(4 * n + 10){
		function<void(int, int, int)> make = [&](int s, int e, int ind){
			if(s == e){
				tree[ind].mn_ab = pref_ab[s];
				tree[ind].mn_bc = pref_bc[s];
				tree[ind].val = INF;
				return;
			}
			int mid = (s + e) >> 1;
			make(s, mid, ind << 1);
			make(mid + 1, e, ind << 1 | 1);
			tree[ind] = merge(tree[ind << 1], tree[ind << 1 | 1]);
		};
		make(0, n, 1);
	}
	void push(int s, int e, int ind){
		if(s != e) {
			tree[ind << 1].l1 += tree[ind].l1;
			tree[ind << 1].l2 += tree[ind].l2;

			tree[ind << 1 | 1].l1 += tree[ind].l1;
			tree[ind << 1 | 1].l2 += tree[ind].l2;
		}
		tree[ind].push();
	}

	void update(int l, int r, int x1, int x2, int s, int e, int ind){
		push(s, e, ind);
		if(l > e || s > r) return;
		if(s >= l && e <= r){
			tree[ind].l1 += x1;
			tree[ind].l2 += x2;
			push(s, e, ind);
			return;
		}
		int mid = (s + e) >> 1;
		update(l, r, x1, x2, s, mid, ind << 1);
		update(l, r, x1, x2, mid + 1, e, ind << 1 | 1);
		tree[ind] = merge(tree[ind << 1], tree[ind << 1 | 1]);
	}
};

signed main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int num_c = 0, num_a = 0, num_b = 0;
	for(int i = 1; i <= n; i++){
		pref_ab[i] = pref_ab[i - 1];
		pref_bc[i] = pref_bc[i - 1];
		if(s[i - 1] == 'a'){
			pref_ab[i]++;
			num_a++;
		}
		else if(s[i - 1] == 'b'){
			pref_ab[i]--;
			pref_bc[i]++;
			num_b++;
		} else{
			pref_bc[i]--;
			num_c++;
		}
	}
	segtree st(n);
	int l1 = 0, l2 = 0;
	function<void(int, int)> upd = [&](char c, int x){
		if(c == 'a'){
			l1 += x;
			num_a += x;
		} else if(c == 'b'){
			l1 -= x;
			l2 += x;
			num_b += x;
		} else{
			l2 -= x;
			num_c += x;
		}
	};
	while(q--){
		int p; char c;
		cin >> p >> c;
		l1 = l2 = 0;
		upd(s[p - 1], -1);
		s[p - 1] = c;
		upd(s[p - 1], 1);
		st.update(p, n, l1, l2, 0, n, 1);
		// trace(num_c);

		int minf = min(min(num_a, num_b), num_c);
		cout << min(minf, num_c + st.tree[1].val) << endl;
	}
}