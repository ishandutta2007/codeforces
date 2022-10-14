#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 55;
using node = array<int, 3>;
node broken{1<<30, 0, 0};

node merge(node l, node r) {
	if(l > r) swap(l, r);
	if(l[0]==r[0]) l[1] += r[1];
	l[2] = 0;
	return l;
}

struct segment_tree
{
	node tr[4 * maxn];
	void init(int l, int r, int idx)
	{
		if(l == r)
		{
			tr[idx] = node{0, 1, 0};
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}
	void push(int l, int r, int idx)
	{
		if(tr[idx][2])
		{
			tr[idx][0] += tr[idx][2];

			if(l != r) {
				tr[2 * idx + 1][2] += tr[idx][2];
				tr[2 * idx + 2][2] += tr[idx][2];
			}

			tr[idx][2] = 0;
		}
	}

	void update(int qL, int qR, int val, int l, int r, int idx)
	{
		push(l, r, idx);

		if(qL > r || l > qR)
			return;

		if(qL <= l && r <= qR)
		{
			tr[idx][2] += val;
			push(l, r, idx);
			return;
		}

		int mid = (l + r) >> 1;
		update(qL, qR, val, l, mid, 2 * idx + 1);
		update(qL, qR, val, mid + 1, r, 2 * idx + 2);

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
int n, a[maxn], on[maxn], b[maxn];
segment_tree st;
void eval(int i, int x) {
	st.update(a[i], n, x, 0, n, 0);
	if(i && on[i-1])
		st.update(max(a[i], a[i-1]), n, -x, 0, n, 0);
	if(i<n && on[i+1])
		st.update(max(a[i], a[i+1]), n, -x, 0, n, 0);
}
void disable(int i) {
	if(!on[i]) return;	
	eval(i, -1);
	on[i] = 0;
}
void enable(int i, int x) {
	if(on[i]) disable(i);
	a[i] = x;
	eval(i, 1);
	on[i] = 1;
}
void print() {
	for(int i = 0; i <= n; i++) {
		auto t = st.query(i, i, 0, n, 0);
		cout << t[0] << ' ';
	}
	cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    st.init(0, n, 0);
    for(int p, x, i = 0; i < n; i++) {
		cin >> p >> x;
		b[x] = p;
		enable(p, x);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		//print();
		auto t = st.query(i, n, 0, n, 0);
		if(t[0] == 1)
			ans += t[1];
		disable(b[i]);
	}
	cout << ans << '\n';
}