#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!" << endl

const long long N = 3e5 + 10;

long long n, l[100100], r[100100], ret[300100];
long long t[100100], cnt;


struct nod {
	nod * l, * r;

	long long val = 0;
	char lazy = 0;

	nod() {
		l = r = 0;
		cnt++;
	}
};


long long value(nod * node, long long l, long long r) {
	if(node == 0) return 0;
	if(node->lazy == 0)
		return node->val; 
	if(node->lazy < 3)
		return (node->lazy - 1) * (r - l + 1);
	return (r - l + 1) - node->val;
}

void push(nod * node, long long l, long long r) {
	if(node->lazy) {
		if(l != r) {
			if(!node->l) node->l = new nod();
			if(!node->r) node->r = new nod();

			if(!node->l->lazy || node->lazy != 3) node->l->lazy = node->lazy;
			else node->l->lazy = 3 - node->l->lazy;
			
			if(!node->r->lazy || node->lazy != 3) node->r->lazy = node->lazy;
			else node->r->lazy = 3 - node->r->lazy;
		}

		if(node->lazy != 3) node->val = (node->lazy - 1) * (r - l  + 1);
		else node->val = (r - l + 1) - node->val;
		node->lazy = 0;
	}
}

void update(nod * node, long long l, long long r, long long x, long long y, long long val) {
	push(node, l, r);


	if(x <= l && r <= y) 
		return void(node->lazy = val);

	long long mid = (l + r) / 2;
	if(x <= mid) {
		if(!node->l) node->l = new nod();
		update(node->l, l, mid, x, y, val);
	}
	if(y > mid) {
		if(!node->r) node->r = new nod();
		update(node->r, mid + 1, r, x, y, val);
	}

	node->val = value(node->l, l, mid) + value(node->r, mid + 1, r);
	
}
vector <long long> v;
map <long long, long long> m;

long long query(nod * node, long long l, long long r) {
	push(node, l, r);
	if(l == r) return l;

	long long mid = (l + r) / 2;

	if(value(node->l, l, mid) < (mid - l + 1)) {
		if(!node->l) return l;
		return query(node->l, l, mid);
	}
	if(!node->r) return mid + 1;
	return query(node->r, mid + 1, r);
}


int main() {
	ios_base::sync_with_stdio(false);
	nod * root =new nod();
	// update(root, 1, N, 3, 4, 2);
	// update(root, 1, N, 1, 6, 3);
	// cout << query(root, 1, N);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> t[i] >> l[i] >> r[i];
		if(t[i] != 3) t[i] = 3 - t[i];
		v.push_back(l[i]);
		v.push_back(r[i]);
		v.push_back(r[i] + 1);
	}

	v.push_back(1);
	sort(v.begin(), v.end());

	int nr = 0;
	for(long long i = 0; i < v.size(); i++) {

		if(m[v[i]]) continue;
		ret[nr] = v[i];
		m[v[i]] = ++nr;
		// dbg(m[x]);
		// dbg_ok;
	}

	for(long long i = 1; i <= n; i++) {
		update(root, 1, N, m[l[i]], m[r[i]], t[i]);
		long long pos = query(root, 1, N) - 1;


		cout << ret[pos] << '\n';
	}
	dbg(cnt);

}