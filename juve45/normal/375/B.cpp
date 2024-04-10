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
int n, m;
string s;
vector <int> v[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s;
		int cnt = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == '1')
				cnt++;
			else 
				cnt = 0;
			v[j].push_back(cnt);
		}
	}
	for(int i = 0; i < m; i++) 
		sort(v[i].begin(), v[i].end(), greater<int>());

	int ans = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			ans = max(ans, (j + 1) * v[i][j]);
	cout << ans << '\n';
}