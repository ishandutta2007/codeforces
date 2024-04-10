#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) {for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n, mnx[44], mny[44], mxx[44], mxy[44], m, tt;
string s[2019], t[2019];

void solve() {
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	int max_letter = -1;
	memset(mxx, -1, sizeof mxx);
	memset(mxy, -1, sizeof mxy);
	for(int i =0 ;i < 26; i++)
		mnx[i] = mny[i] = 40000;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] != '.') {
				int l = s[i][j] - 'a';
				// dbg(l);
				max_letter = max(l, max_letter);
				mnx[l] = min(mnx[l], i);
				mxx[l] = max(mxx[l], i);
				mny[l] = min(mny[l], j);
				mxy[l] = max(mxy[l], j);
			}

	for(int i = 0; i < n; i++)
		t[i] = string(m, '.');

	// dbg(max_letter);
	for(int l = max_letter - 1; l >= 0; l--)
		if(mnx[l] == 40000)
			mnx[l] = mnx[l + 1],
			mny[l] = mny[l + 1],
			mxx[l] = mxx[l + 1],
			mxy[l] = mxy[l + 1];

	vector <vector <int> > ans;

	for(int l = 0; l <= max_letter; l++) {
		if(mnx[l] != mxx[l] && mny[l] != mxy[l]) {
			cout << "NO\n";
			return;
		}

		for(int i = mnx[l]; i <= mxx[l]; i++)
			for(int j = mny[l]; j <= mxy[l]; j++)
				t[i][j] = 'a' + l;

		ans.push_back({mnx[l] + 1, mny[l] + 1, mxx[l] + 1, mxy[l] + 1});
	}
	// dbg(ans);
	for(int i = 0; i < n; i++)
		if(s[i] != t[i]) {
			// dbg(i, s[i], t[i]);
			cout << "NO\n";
			return ;
		}
	cout << "YES\n";
	cout << max_letter + 1 << '\n';
	for(auto i : ans) cout << i << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> tt;
	while(tt--) solve();

}