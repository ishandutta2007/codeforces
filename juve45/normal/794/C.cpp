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

// const int N = ;
int n;

string f, b, s, t;
deque<char> ds, dt;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;
	cin >> t;
	n = s.size();
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	while(s.size() > (n + 1) / 2) s.pop_back();
	reverse(s.begin(), s.end());

	reverse(t.begin(), t.end());
	while(t.size() > n / 2) t.pop_back();
	reverse(t.begin(), t.end());

	for(auto i : s)
		ds.push_back(i);

	for(auto i : t)
		dt.push_back(i);

	// dbg(s, t);
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 1) {
			if(i == n || ds.back() < dt.back()) {
				f.push_back(ds.back());
				ds.pop_back();
			} else {
				b.push_back(ds.front());
				ds.pop_front();
			}
		} else {

			if(i == n || dt.back() > ds.back()) {
				f.push_back(dt.back());
				dt.pop_back();
			} else {
				b.push_back(dt.front());
				dt.pop_front();
			}
		}
	}
	reverse(b.begin(), b.end());
	cout << f << b << '\n';
}