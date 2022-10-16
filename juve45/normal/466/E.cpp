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

const int N = 100100;

int x,n,m,y, a, b, t;
vector<int> v[N], euler, nivel, cc[N];
int rmq[20][2 * N],first[N],l2[2 * N], col[N], ok[N], who[N], ans[N];
vector <pair <pair<int, int>, pair<int, int> > > ord;

void unite(int x, int y) {
	if(cc[x].size() > cc[y].size()) swap(x, y);
	for(auto i : cc[x]) {
		col[i] = y;
		cc[y].push_back(i);
	}
	cc[x].clear();
}

void dfs(int nod, int niv)
{
	// dbg(nod);
  first[nod] = euler.size();

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
  for (int i=2;i<=2 * n;i++)
    l2[i]=l2[i/2]+1;

  dfs(n,1);
  
  for(int i = 0;i < euler.size();i++)
    rmq[0][i] = i;
  
  for (int i = 1;(1<<i) < euler.size();i++)
    for (int j = 0; j + (1 << i)-1 < euler.size(); j++) 
      if (nivel[rmq[i-1][j]]<nivel[rmq[i-1][j+(1<<(i-1))]])
        rmq[i][j] = rmq[i - 1][j];
      else 
        rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	int elem = 1, sz = 0;

	for(int i = 1; i <= n; i++) {
		col[i] = i;
		cc[i].push_back(i);
	}

	for(int i = 1; i <= m; i++) {
	
		cin >> t;
	
		if(t == 1) {
			cin >> a >> b;
			v[b].push_back(a);
			ok[a] = 1;
			ord.push_back({{elem, t}, {a, b}});
		} else if(t == 2) {
			cin >> a;
			ord.push_back({{elem, t}, {a, b}});
			elem++;
		} else {
			cin >> a >> b;
			ord.push_back({{b, t}, {a, sz}});
			sz++;
		}
	}

	for(int i = 1; i <= n; i++)
		if(!ok[i]) {
			v[n + 1].push_back(i);
			// dbg(n, i);
		}
	n++;

	dbg_ok;

	sort(ord.begin(), ord.end());

	pre();

	dbg_ok;

	for(auto p : ord) {
		if(p.st.nd == 1)
			unite(col[p.nd.st], col[p.nd.nd]);
		else if(p.st.nd == 2)
			who[p.st.st] = p.nd.st;
		else {
			// this will be fun
			// dbg(p);
			int me = p.nd.st;
			int node = who[p.st.st];
			// dbg(node);
			// dbg(me);
			if(col[me] == col[node] && LCA(me, node) == me)
				ans[p.nd.nd] = 1;
		}

	}
	// dbg(elem);
	for(int i = 0; i < sz; i++)
		if(ans[i]) cout << "YES\n";
		else cout << "NO\n";

}