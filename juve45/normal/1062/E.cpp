#include <bits/stdc++.h>

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

const int N = 200100;
 
vector<int> v[N], euler, nivel;
int rmq[20][2 * N],first[N],l2[N], second[N], st[4 * N], st2[4 * N], p[N], lvl[N];
int x,n,m,y, q, l, r;
 
void dfs(int nod, int niv)
{
  first[nod] = euler.size();
  lvl[nod] = niv;

  for (auto i : v[nod]) {
    euler.push_back(nod);
    nivel.push_back(niv);
    dfs(i, niv+1);
  }
  euler.push_back(nod);
  nivel.push_back(niv);

}
 
int LCA(int x, int y) {
  if(first[x] > first[y]) 
    swap(x, y);
  
  int l = l2[first[y]-first[x]+1];

  if (nivel[rmq[l][first[x]]] < nivel[rmq[l][first[y]-(1<<l)+1]])
    return euler[rmq[l][first[x]]];
  return euler[rmq[l][first[y]-(1<<l)+1]];
}

void pre() {
  
  for (int i=2;i<=2*n;i++)
    l2[i]=l2[i/2]+1;

  dfs(1,1);
  
  for (int i = 0;i < euler.size();i++)
    rmq[0][i] = i;
  
  for (int i = 1;(1<<i) < euler.size();i++)
    for (int j = 0; j + (1 << i)-1 < euler.size(); j++) 
      if (nivel[rmq[i-1][j]]<nivel[rmq[i-1][j+(1<<(i-1))]])
        rmq[i][j] = rmq[i - 1][j];
      else 
        rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
}

void build(int * st, int node, int l, int r) {
	st[node] = l;
	if(l == r) return;
	int mid = (l + r) / 2;
	build(st, 2 * node, l, mid);
	build(st, 2 * node + 1, mid + 1, r);
}

int que(int * st, int * vals, int node, int l, int r, int x, int y) {
	if(x <= l && r <= y)
		return st[node];

	int mid = (l +  r) / 2;
	int ans1 = -1, ans2 = -1;
	if(x <= mid) ans1 = que(st, vals, 2 * node, l, mid, x, y);
	if(mid < y) ans2 = que(st, vals, 2 * node + 1, mid + 1, r, x, y);
	// dbg(node, l, r, st[node], mid);
	// dbg(ans1, ans2);
	
	if(ans1 == -1) return ans2;
	if(ans2 == -1) return ans1;
	if(vals[ans1] < vals[ans2]) return ans1;
	return ans2;
}

void update(int * st, int * vals, int node, int l , int r, int pos) {
	// dbg(node, l, r);
	if(l == r)
		return;

	int mid = (l + r) / 2;
	if(pos <= mid) update(st, vals, 2 * node, l, mid, pos);
	else update(st, vals, 2 * node + 1, mid + 1, r, pos);

	if(vals[st[2 * node]] < vals[st[2 * node + 1]])
		st[node] = st[2 * node];
	else 
		st[node] = st[2 * node + 1];
	// dbg(node, l, r, st[node], st[2 * node], st[2 * node + 1]);
}


int LLCA(int l, int r, int bad) {

	int tmp = first[bad];
	first[bad] = 1e9;
	second[bad] = 1e9;

	update(st, first, 1, 1, n, bad);
	update(st2, second, 1, 1, n, bad);

	// dbg_v(first, n + 1);

	int L = que(st, first, 1, 1, n, l, r);
	int R = que(st2, second, 1, 1, n, l, r);

	// dbg(L, R, bad, l, r);

	first[bad] = tmp;
	second[bad] = -tmp;

	update(st, first, 1, 1, n, bad);
	update(st2, second, 1, 1, n, bad);

	return LCA(L, R);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
	for(int i= 2; i <= n; i++) {
		cin >> p[i];
		v[p[i]].push_back(i);
	}

	pre();
	// dbg(euler);

	for(int i = 1; i <= n; i++)
		second[i] = -first[i];

	// dbg_v(first, n + 1);
	// dbg_v(second, n + 1);

	build(st, 1, 1, n);
	build(st2, 1, 1, n);

	for(int i = 1; i <= n; i++) {
		update(st, first, 1, 1, n, i);
		update(st2, second, 1, 1, n, i);
	}

	// dbg(que(st, first, 1,1, n, 4, 6));
	// LLCA(3, 6, 3);
	// return 0;

	// dbg(lvl[1]);
	// dbg(que(st2, second, 1, 1, n, 4, 8));
	// return 0;

	for(int i = 1; i <= q; i++) {
		cin >> l >> r;
		// dbg(l, r);
		int x1 = que(st, first, 1, 1, n, l, r);
		int x2 = que(st2, second, 1, 1, n, l, r);
		// dbg(x1, x2);
		int y1 = LLCA(l, r, x1);
		int y2 = LLCA(l, r, x2);
		
		if(lvl[y1] >= lvl[y2])  {
			cout << x1 << ' ';
			cout << lvl[y1] - 1 << '\n';
		}
		else {
			cout << x2 << ' ' ;
			cout << lvl[y2] - 1 << '\n';
		}
	}

}