#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<18, mod = 998244353;
using ll = long long;

int n, m;

struct node
{
	ll a, b, sum;
	node() {sum = 0; a = 1;b = 0;}
	node(int val)
	{
		sum = val;
		a = 1;b = 0;
	}
	void apply(ll c, ll d) {
		ll na = c*a%mod;
		ll nb = (c*b + d)%mod;
		a = na, b = nb;
	}
};

node temp, broken;

node merge(node l, node r)
{
	temp.sum = (l.sum + r.sum)%mod;
	temp.a = 1;temp.b = 0;
	return temp;
}

struct segment_tree
{
	node tr[4 * maxn];

	void push(int l, int r, int idx)
	{
		tr[idx].sum = ( ((r - l + 1) * tr[idx].b) + (tr[idx].sum * tr[idx].a) )%mod;
		if(l != r)
		{
			tr[2 * idx + 1].apply(tr[idx].a, tr[idx].b);
			tr[2 * idx + 2].apply(tr[idx].a, tr[idx].b);
		}
		tr[idx].a = 1;tr[idx].b = 0;
	}

	void init(int l, int r, int idx)
	{
		if(l == r)
		{
			tr[idx] = node();
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	void update(int qL, int qR, int A, int B, int l, int r, int idx)
	{
		push(l, r, idx);

		if(qL > r || l > qR)
			return;

		if(qL <= l && r <= qR)
		{
			tr[idx].apply(A, B);
			push(l, r, idx);
			return;
		}

		int mid = (l + r) >> 1;
		update(qL, qR, A, B, l, mid, 2 * idx + 1);
		update(qL, qR, A, B, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	node query(int qL, int qR, int l, int r, int idx)
	{
		push(l, r, idx);

		if(l > qR || r < qL)
			return broken;

		if(qL <= l && r <= qR)
			return tr[idx];

		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};

segment_tree st;
set<array<int, 2>> R[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	st.init(1, n, 0);
	for(int t, l, r, x, i = m; i--;) {
		cin >> t >> l >> r;
		int _l = l, _r = r;
		if(t == 1) {
			cin >> x;
			int c = l;
			while(c <= r) {
				auto it = R[x].lower_bound({c, 0});//{r, l}
				int np;
				if(it == R[x].end()) np = r, t = 0;
				else {
					//cout << it->at(0) << " " << it->at(1) << '\n';
					if(c >= it->at(1)) {
						l = min(l, it->at(1));
						t = 1;
						np = it->at(0);
					} else {
						t = 0;
						np = min(r, it->at(1)-1);
					}
				}
				//cout << c << " -> " << np << " " << (1+t) << " " << (!t) << '\n';
				st.update(c, min(r, np), 1+t, !t, 1, n, 0);
				c = np+1;
				if(it != R[x].end() && t) R[x].erase(it);
			}
			R[x].insert({c-1, l});
		} else cout << st.query(l, r, 1, n, 0).sum << '\n';
		/*
		for(int i = 1; i <= n; i++) {
			if(R[i].empty()) continue;
			cout << i << " : ";
			for(auto [r, l] : R[i]) cout << l << " | " << r << " ; "; cout << '\n';
		}*/
		//for(int i = _l; i <= _r; i++) cout << st.query(i, i, 1, n, 0).sum << " "; cout << '\n';
		
	}
}