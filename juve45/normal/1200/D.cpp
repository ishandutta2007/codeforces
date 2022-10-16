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

const int N = 2019;
int n, k, ans, tot;
int w[N][N], rmn[N], rmx[N], cmn[N], cmx[N];
string s[N];

void put(int cmin, int rmin, int cmax, int rmax) {
	w[rmin][cmin] += 1;
	w[rmin][cmax + 1] += -1;
	w[rmax + 1][cmin] += -1;
	w[rmax + 1][cmax + 1] += 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	memset(rmn, 0x3f, sizeof rmn);
	memset(cmn, 0x3f, sizeof cmn);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> s[i];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) 
			if(s[i][j] == 'B') {
				rmn[i] = min(rmn[i], j);
				rmx[i] = max(rmx[i], j);
				cmn[j] = min(cmn[j], i);
				cmx[j] = max(cmx[j], i);
			}
	}

	for(int i = 0; i < n; i++) {
		if(cmn[i] > cmx[i]) {
			tot ++;
			continue;
		}
		int rmin = max(0, i - k + 1), rmax = i;
		int cmax = cmn[i], cmin = max(cmx[i] - k + 1, 0);
		// dbg(i, rmin, rmax, cmin, cmax);
		if(cmx[i] - cmn[i] + 1 <= k) 
			put(cmin, rmin, cmax, rmax);
	}


	for(int i = 0; i < n; i++) {
		if(rmn[i] > rmx[i]) {
			tot ++;
			continue;
		}
		int cmin = max(0, i - k + 1), cmax = i;
		int rmax = rmn[i], rmin = max(rmx[i] - k + 1, 0);
		// dbg(i, rmin, rmax, cmin, cmax);
		if(rmx[i] - rmn[i] + 1 <= k) 
			put(cmin, rmin, cmax, rmax);
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			if(i == 0)
				w[i][j] += w[i][j - 1];
			else if(j == 0)
				w[i][j] += w[i - 1][j];
			else 
				w[i][j] += w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
			ans = max(ans, w[i][j]);
		}
	cout << tot + ans << '\n';
}