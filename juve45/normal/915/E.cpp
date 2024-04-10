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

const int N = 300100;
int n, x, ans, k, m, q, a, b, res[N];

set <pair<pair<int, int>, int> > s;
void prel(pair<int, int> a, int ka, pair <int, int> b, int k) {

	int del = ka * (a.nd - a.st + 1);
	if(a.st < b.st) {
		s.insert({{a.st, b.st - 1}, ka});
		del -= ka * (b.st - a.st);
	}

	if(b.nd < a.nd) {
		s.insert({{b.nd + 1, a.nd}, ka});
		del -= ka * (a.nd - b.nd);
	}

	ans -= del;
} 


int main()
{
	ios_base::sync_with_stdio(false);	

	// cin >> n >> m;
	scanf("%d %d", &n, &m);
	s.insert({{1, n}, 1});

	ans = n;
	for(int i = 1; i <= m; i++) {
		// cin >> a >> b >> k;
		scanf("%d %d %d", &a, &b, &k);
		k--;
		auto p = s.lower_bound({{a + 1, 0}, 0});
		p--;
		// dbg_ok;
		// dbg(i, *p);
		// inter
		auto pp = *p;
		auto er = p;
		p++;
		s.erase(er);
		prel(pp.st, pp.nd, {a, b}, k);

		while(p != s.end() && p->st.nd <= b) {
			if(p->nd == 1) ans -= p->st.nd - p->st.st + 1;
			auto er = p;
			p++;
			s.erase(er);
		}
		// dbg_ok;
		// dbg(s);
		if(p != s.end() && p->st.st <= b) {
			pp = *p;
			prel(pp.st, pp.nd, {a, b}, k);
			s.erase(p);
		}

		s.insert({{a, b}, k});
		ans += (b - a + 1) * k;
		
		// dbg(s);
		// res[i] = ans;
		printf("%d\n", ans);

		//inter
	}
	// for(int i = 1; i <= m; i++) 
		// printf("%d\n", res[i]);
		// cout << res[i] << '\n';
}