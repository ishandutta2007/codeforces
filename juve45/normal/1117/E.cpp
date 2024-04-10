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

const int N = 10100;
int n;

void inc(string &s) {
	if(s[2] == 'z' && s[1] == 'z')
		s[0]++, s[1] = s[2] = 'a';
	else if(s[2] == 'z')
		s[1]++, s[2] = 'a';
	else s[2]++;
}

string s, r[N], t[N], rs[N], ans;
map <string, int> m;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;

	int n = s.size();
	string ss = "aaa";

	for(int i = 0; i < n; i++) {
		t[i] = ss;
		m[ss] = i;
		inc(ss);
	}

	for(int i = 0; i < 3; i++) {
		cout << "? ";
		for(int j = 0; j < n; j++)
			cout << t[j][i];
		cout << endl;
		cin >> r[i];
	}
	// dbg(m);
	ans = s;

	for(int j = 0; j < n; j++) {
		rs[j] += r[0][j];
		rs[j] += r[1][j];
		rs[j] += r[2][j];
		// dbg(j, rs[j]);
		int pos = m[rs[j]];
		ans[pos] = s[j];
	}
	cout << "! " << ans << '\n';
}