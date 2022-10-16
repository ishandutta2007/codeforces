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
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, x[N], y[N], m, a, b;
vector <long long> v[N];


vector<long long> euler, nivel;
long long rmq[20][200010],first[100010],l2[200010];
 
void dfs(long long nod, long long niv)
{
  first[nod] = euler.size();

  for (auto i : v[nod]) {
    euler.push_back(nod);
    nivel.push_back(niv);
    dfs(i, niv+1);
  }
  euler.push_back(nod);
  nivel.push_back(niv);

}
 
long long LCA(long long x, long long y) {
  if(first[x] > first[y]) 
    swap(x, y);
  
  long long l = l2[first[y]-first[x]+1];

  if (nivel[rmq[l][first[x]]] < nivel[rmq[l][first[y]-(1<<l)+1]])
    return euler[rmq[l][first[x]]];
  return euler[rmq[l][first[y]-(1<<l)+1]];
}

void pre() {
  for (long long i=2;i<=2*n;i++)
    l2[i]=l2[i/2]+1;

  dfs(n,1);
  
  for (long long i = 0;i < euler.size();i++)
    rmq[0][i] = i;
  
  for (long long i = 1;(1<<i) < euler.size();i++)
    for (long long j = 0; j + (1 << i)-1 < euler.size(); j++) 
      if (nivel[rmq[i-1][j]]<nivel[rmq[i-1][j+(1<<(i-1))]])
        rmq[i][j] = rmq[i - 1][j];
      else 
        rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
}



pair<long long, long long> slope(long long a, long long b) {
	long long dx = x[b] - x[a];
	long long dy = y[b] - y[a];
	return {dy, dx};
}

bool lesss(pair<long long, long long> a, pair<long long, long long> b) {
	return a.st * b.nd < a.nd * b.st;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	vector<long long> st;
	st.push_back(n);
	for(long long i = n - 1; i > 0; i--) {

		while(st.size() >= 2 && lesss(slope(i, st.back()), slope(i, st[st.size() - 2])))
			st.pop_back();

		// dbg(i, st.back());
		v[st.back()].push_back(i);
		st.push_back(i);
	}

	pre();

	cin >> m;
	for(long long i = 1; i <= m; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << ' ';
	}

}