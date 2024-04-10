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

const int N = 5005;
int n, lcp[N][N], sl[N][N], tl[N][N], mxs[N], mxt[N];
string s, t;

void computeLCP(string &s, string &t, int lcp[N][N]) {
	for(int i = s.size() - 1; i >= 0; i--)
		for(int j = t.size() - 1; j >= 0; j--)
			if(s[i] == t[j])
				lcp[i][j] = 1 + lcp[i + 1][j + 1];
			else lcp[i][j] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	

	cin >> s >> t;
	computeLCP(s, t, lcp);
	computeLCP(s, s, sl);
	computeLCP(t, t, tl);

	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < s.size(); j++) {
			if(i == j) continue;
			mxs[i] = max(sl[i][j], mxs[i]);
		}
	}
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size(); j++) {
			if(i == j) continue;
			mxt[i] = max(tl[i][j], mxt[i]);
		}
	}

	int ans = 1e7;
	for(int i = 0; i < s.size(); i++)
		for(int j = 0; j < t.size(); j++) {
			if(mxs[i] < lcp[i][j] && mxt[j] < lcp[i][j])
			ans = min(max(mxs[i], mxt[j]) + 1, ans);
		}
	if(ans > 5e4) ans = -1;
	cout << ans << '\n';
}