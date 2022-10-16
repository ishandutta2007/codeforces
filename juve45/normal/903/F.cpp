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

const int N = 1010;
int n, a[5], dp[N][(1 << 16) + 15];
string s[5];

vector <vector <int> > configs;
vector <int> tt;

int val(vector <int> t) {
	reverse(t.begin(), t.end());
	int last = 0;
	for(int i = 0; i < 4; i++)
		last = max(last, i + max(t[i], 1));
	return last;
}

void bkt() {
	// dbg(tt);
	int load = 0; 
	//if(!tt.empty()) load = max(0, tt.back() - 1);
	if(tt.size() + load >= 4) {
		if(val(tt) == 4) configs.push_back(tt);
		return;
	}
	for(int i = 0; i <= 4; i++) {
		tt.push_back(i);
		bkt();
		tt.pop_back();
	}
}


void config() {
	bkt();
	// dbg(configs.size());
	dbg(val({1, 0, 1, 1}));
}

int get_cost(const vector <int> &t) {
	int res = 0;
	for(auto i : t) res += a[i];
	return res;
}

int tranz(int pos, int conf, vector <int> t) {
	int mat[5][5];
	// dbg(conf);
	memset(mat, 0, sizeof mat);
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			mat[i][j] = conf % 2, conf /= 2;

	// dbg_v(mat[0], 4);
	// dbg_v(mat[1], 4);
	// dbg_v(mat[2], 4);
	// dbg_v(mat[3], 4);
	// dbg(t);

	for(int i = 0; i < 4 && !t.empty(); i++) {
		int me = t.back(); t.pop_back();
		for(int j = 0; j < me; j++)
			for(int k = 0; k < me; k++)
				if(i + j < 4)
					mat[i + j][k] = 0;
	}
	for(int i = 0; i < 4; i++)
		if(mat[i][0] == 1) return -1;
		else mat[i][4] = (s[i][pos] == '*');


	// dbg_v(mat[0], 5);
	// dbg_v(mat[1], 5);
	// dbg_v(mat[2], 5);
	// dbg_v(mat[3], 5);

	int msk = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 1; j <= 4; j++)
			if(mat[i][j])
				msk += (1 << (4 * i + (j - 1)));
	return msk;
}

int main() {
	ios_base::sync_with_stdio(false);	

	config();

	cin >> n;
	for(int i = 1; i <= 4; i++) 
		cin >> a[i];
	a[3] = min(a[3], a[4]);
	a[2] = min(a[3], a[2]);
	a[1] = min(a[2], a[1]);

	for(int i = 0; i < 4; i++)
		cin >> s[i], s[i] += "......";

	int msk = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(s[i][j] == '*')
				msk += (1 << (4 * i + j));

	memset(dp, 0x3f, sizeof dp);
	dp[0][msk] = 0;

	for(int i = 0; i < n; i++) {
		for(int conf = 0; conf < (1 << 16); conf++) {
			if(dp[i][conf] > 1e7) continue;

			// dbg(i, conf, dp[i][conf]);
			for(auto t : configs) {
				int cost = get_cost(t);
				int new_conf = tranz(i + 4, conf, t);
		
				if(new_conf >= 0) {
					dp[i + 1][new_conf] = min(dp[i + 1][new_conf], dp[i][conf] + cost);
				}
			}
		}
	}

	cout << dp[n][0] << '\n';
}