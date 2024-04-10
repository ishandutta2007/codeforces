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

const int N = 200100;
int c[N], t;

void solve() {
	int n, min_cif = 10;
	vector <pair <int, int>> v;
	string d;

	cin >> n;
	cin >> d;

	for(int i = 0; i < n; i++) 
		v.push_back({d[i] - '0', i});

	sort(v.begin(), v.end());
	// dbg(v);

	int col = 1, pos, val;
	
	int last1 = v[0].nd;
	int last_val1 = v[0].st;
	int first2 = 10;
	c[v[0].nd] = 1;

	for(int i = 1; i < v.size(); i++) {
		
		if(v[i].nd > last1 && v[i].st <= first2) {
			c[v[i].nd] = 1;
			last1 = v[i].nd;
		} else {
			c[v[i].nd] = 2;
			if(first2 == 10) first2 =  v[i].st;
		}
	}
	// dbg_v(c, n);
	string s1, s2, ss, sr;

	for(int i = 0; i < n; i++)
		if(c[i] == 1)
			s1 += d[i];
		else
			s2 += d[i];
	// dbg(s1, s2);
	ss = s1 + s2;
	sr = ss;
	sort(sr.begin(), sr.end());
	if(ss != sr) 
		return void(cout << "-\n");
	
	for(int i = 0; i < n; i++)
		cout << c[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;
	while(t--) {
		solve();
	}
}