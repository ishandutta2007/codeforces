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

const int N = 1005;
int n, m, m2[N], m3[N], ans;
string s[N];

vector <pair<int, char> > v[N], curr;
pair<int, int> last[N], last2[N];

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];

	for(int j = 0; j < m; j++) {

		int cnt = 1;
		for(int i = 1; i < n; i++)
			if(s[i][j] == s[i - 1][j])
				cnt++;
			else 
				v[j].push_back({cnt, s[i - 1][j]}), cnt = 1;

		v[j].push_back({cnt, s[n - 1][j]});

		// dbg(v[j]);
		// dbg_/v(m3);

		int pos = v[j][0].st;
		
		for(int k = 1; k +1 < v[j].size(); k++) {
			if(v[j][k - 1].st >= v[j][k].st && v[j][k + 1].st >= v[j][k].st) {
				
				int col = v[j][k - 1].nd * 256 * 256 + 256 * v[j][k].nd + v[j][k + 1].nd;
				
				if(last[pos] == make_pair(v[j][k].st, col))
					m2[pos] = m3[pos] + 1;
				else 
					m2[pos] = 1;
				
				ans += m2[pos];
				last2[pos] = make_pair(v[j][k].st, col);
				// dbg(pos, last2[pos]);
			}
			pos += v[j][k].st;
		}

		for(int ii = 0; ii < N; ii++)
			m3[ii] = m2[ii], last[ii] = last2[ii];

		memset(m2, 0, sizeof m2);

		// dbg(j, ans);
	}

	cout << ans << '\n';

}