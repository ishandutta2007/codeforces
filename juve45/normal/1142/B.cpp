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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

using ll = long long;
using ull = unsigned long long;
const int N = 200100;

int n, m, q, l, r, p[N], a[N], last[N], arb[4 * N], prv[N], sir[N];
vector <int> v[N];

void update(int nod, int pos, int val, int left, int right)
{
	if(left == right) {
		arb[nod] = val;
		return;
	}
	int mid=(left+right)/2;
	if (pos<=mid)
		update(2*nod, pos, val, left,mid);
	else update(2*nod+1, pos, val, mid+1, right);
	arb[nod]=max(arb[2 * nod], arb[2 * nod + 1]);
}
 
int query(int nod, int a, int b, int left, int right)
{
	if (left>=a&&right<=b)
		return arb[nod];
	int mid= (left+right)/2;
	
	int ansl=-1;
	int ansr=-1;

	if (a<=mid)
		ansl=query(2*nod, a, b, left, mid);
	if (b>=mid+1)
		ansr=query(2*nod+1, a, b, mid+1, right);
	return max(ansl, ansr);
}

vector <int> st;

void dfs(int node) {
	st.push_back(node);
	
	// dbg(node, st);
	if(st.size() >= n) {
		// dbg(node, st[st.size() - n]);
		update(1, node, st[st.size() - n], 1, m);
	}

	for(auto i : v[node])
		dfs(i);
	st.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= m; i++) cin >> a[i];

	int cnt = 0;

	p[0] = p[n];
	p[n + 1] = p[1];
	for(int i = 1; i <= n; i++) 
		prv[p[i]] = p[i - 1];

	for(int i = 1; i <= m; i++) {
		v[last[prv[a[i]]]].push_back(i);
		last[a[i]] = i;
	}

	for(auto i : v[0])
		dfs(i);

	for(int i = 1; i <= q; i++) {
		cin >> l >> r;
		// dbg(l, r);
		// dbg(query(1, l, r, 1, n));
		cout << (query(1, l, r, 1, m) >= l);
	}
	cout << '\n';
	return 0;
}