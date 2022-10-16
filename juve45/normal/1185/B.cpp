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

vector <pair<char, int> > mk(string s) {
	vector <pair<char, int> > ret;
	for(auto i : s)
		if(ret.empty() || ret.back().st != i)
			ret.push_back({i, 1});
		else ret.back().nd++;
	return ret;
}

string solve() {
	string s, t;
	cin >> s >> t;
	auto v1 = mk(s);
	auto v2 = mk(t);
	if(v1.size() != v2.size())
		return "NO\n";
	for(int i = 0; i < v1.size(); i++) {
		if(v1[i].st != v2[i].st || v1[i].nd > v2[i].nd)
			return "NO\n";
	}
	return "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << solve();
	}
}