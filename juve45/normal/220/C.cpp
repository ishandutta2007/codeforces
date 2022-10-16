#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << '['; for(auto e : v) out << e << ' '; return out << ']';}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, a[N], pa[N], b[N], pb[N], ans, vc[N], vd[N];

set <pair<int, int> > d, c;
vector <int> scot[N], bag[N];

int val(int x, int pas = 0) {
	return abs(pa[x] - ((pb[x] + n - pas) % n));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pa[a[i]] = i;
	}

	for(int i = 0; i < n; i++) {
		cin >> b[i];	
		pb[b[i]] = i;		
	}
	ans = b[0];

	for(int i = 0; i < n; i++) {
		if(val(b[i]) < val(ans))
			ans = b[i];

		if(i > pa[b[i]]) {
			vd[b[i]] = val(b[i]);
			d.insert({val(b[i]), b[i]});

			scot[i - pa[b[i]]].push_back(b[i]);
			bag[i].push_back(b[i]);
		} else {
			vc[b[i]] = val(b[i]);
			c.insert({val(b[i]), b[i]});

			bag[i].push_back(b[i]);
			scot[i + n - pa[b[i]]].push_back(b[i]);
		}
	}
	// dbg(ans);
	cout << val(ans) << '\n';

	for(int i = 1; i < n; i++) {
		for(auto j : bag[i - 1]) {
			vd[j] = val(j, i) + i;
			d.insert({val(j, i) + i, j});
			c.erase({vc[j], j});
		}

		auto p1 = make_pair(1, 1);
		auto p2 = make_pair(1, 1);
		if(!d.empty())
			p1 = *d.begin();
		if(!c.empty())
			p2 = *c.begin();

		// dbg(c, d);
		cout << min(val(p1.nd, i), val(p2.nd, i)) << '\n';

		for(auto j : scot[i]) {
			vc[j] = val(j, i) - i;
			d.erase({val(j, i) + i, j});
			c.insert({val(j, i) - i, j});
		}
		
	}	
	// dbg(d);
}